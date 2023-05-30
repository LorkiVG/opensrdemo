#include "Context.h"
#include "FormManager.h"
#include "WindowManager.h"

bool ProcessKeyDownShortcutsDefault(Rml::Context* context, Rml::Input::KeyIdentifier key, int key_modifier, float native_dp_ratio, bool priority)
{
	if (!context) return true;

	// Result should return true to allow the event to propagate to the next handler.
	bool result = false;

	// This function is intended to be called twice by the backend, before and after submitting the key event to the context. This way we can
	// intercept shortcuts that should take priority over the context, and then handle any shortcuts of lower priority if the context did not
	// intercept it.
	if (priority)
	{
		// Priority shortcuts are handled before submitting the key to the context.

		// Toggle debugger and set dp-ratio using Ctrl +/-/0 keys.
		if (key == Rml::Input::KI_F8)
		{
			Rml::Debugger::SetVisible(!Rml::Debugger::IsVisible());
		}
		else if (key == Rml::Input::KI_0 && key_modifier & Rml::Input::KM_CTRL)
		{
			context->SetDensityIndependentPixelRatio(native_dp_ratio);
		}
		else if (key == Rml::Input::KI_1 && key_modifier & Rml::Input::KM_CTRL)
		{
			context->SetDensityIndependentPixelRatio(1.f);
		}
		else if ((key == Rml::Input::KI_OEM_MINUS || key == Rml::Input::KI_SUBTRACT) && key_modifier & Rml::Input::KM_CTRL)
		{
			const float new_dp_ratio = Rml::Math::Max(context->GetDensityIndependentPixelRatio() / 1.2f, 0.5f);
			context->SetDensityIndependentPixelRatio(new_dp_ratio);
		}
		else if ((key == Rml::Input::KI_OEM_PLUS || key == Rml::Input::KI_ADD) && key_modifier & Rml::Input::KM_CTRL)
		{
			const float new_dp_ratio = Rml::Math::Min(context->GetDensityIndependentPixelRatio() * 1.2f, 2.5f);
			context->SetDensityIndependentPixelRatio(new_dp_ratio);
		}
		else
		{
			// Propagate the key down event to the context.
			result = true;
		}
	}
	else
	{
		// We arrive here when no priority keys are detected and the key was not consumed by the context. Check for shortcuts of lower priority.
		if (key == Rml::Input::KI_R && key_modifier & Rml::Input::KM_CTRL)
		{
			for (int i = 0; i < context->GetNumDocuments(); i++)
			{
				Rml::ElementDocument* document = context->GetDocument(i);
				const Rml::String& src = document->GetSourceURL();
				if (src.size() > 4 && src.substr(src.size() - 4) == ".rml")
				{
					document->ReloadStyleSheet();
				}
			}
		}
		else
		{
			result = true;
		}
	}

	return result;
}


Context::Context(std::string name, int width, int height, KeyDownCallback keyDownCallback, bool powerSave)
{
    this->context = Rml::CreateContext(name, Rml::Vector2i(width, height));
    if(keyDownCallback == nullptr)
    {
        this->SetKeyDownCallback(ProcessKeyDownShortcutsDefault);
    }
    else
    {
        this->SetKeyDownCallback(keyDownCallback);
    }
	this->SetPowerSave(powerSave);
}

Context::~Context() 
{
    for(std::map<const std::string, FormManager*>::iterator formmanager = formManagers.begin(); formmanager != formManagers.end(); ++formmanager)
    {
        delete formmanager->second;
        formManagers.erase(formmanager);
    }
    for(std::map<const std::string, WindowManager*>::iterator windowmanager = windowManagers.begin(); windowmanager != windowManagers.end(); ++windowmanager)
    {
        delete windowmanager->second;
        windowManagers.erase(windowmanager);
    }
};

Rml::Context* Context::Get() const
{
    return this->context;
}

std::string Context::GetName() const
{
    return this->context->GetName();
}

void Context::UnloadAllDocuments()
{
    this->context->UnloadAllDocuments();
}


Rml::ElementDocument* Context::LoadDocument(const fs::path& path)
{
    return this->context->LoadDocument(path.string());
}

//KeyDown Events Callbacks
KeyDownCallback Context::GetKeyDownCallback()
{
    return this->keyDownCallback;
}

void Context::SetKeyDownCallback(KeyDownCallback keyDownCallback)
{
    this->keyDownCallback = keyDownCallback;
}

bool Context::GetPowerSave()
{
    return this->powerSave;
}

void Context::SetPowerSave(bool powerSave)
{
    this->powerSave = powerSave;
}

//Добавить форму - Add form
void Context::AddWindow(Window* window)
{
    window->SetContext(this);
    this->windows.insert(std::pair<const std::string, Window*>(window->GetName(), window));
}
//Получить окно - Get window
Window* Context::GetWindow(const std::string name) const
{
    std::map<const std::string, Window*>::const_iterator window = this->windows.find(name);
    if (window != this->windows.end())
    {
        return window->second;
    }
    else
    {
        return nullptr;
    }
}

//Вырезать окно - Cut window
//Внимание при подобной отвязке окна, его требуется привязать сразу куда-то иначе его View будет отображаться на старом контексте - Attention when unlinking a window like this, it must be linked somewhere immediately otherwise its View will be displayed on the old context
Window* Context::CutWindow(const std::string name)
{
    std::map<const std::string, Window*>::iterator window = this->windows.find(name);
    if (window != this->windows.end())
    {
        this->windows.erase(window);
        return window->second;
    }
    else 
    {
        return nullptr;
    }
}

//Удалить окно - Delete window
void Context::DeleteWindow(const std::string name)
{
    std::map<const std::string, Window*>::iterator window = this->windows.find(name);
    if (window != this->windows.end())
    {
        delete window->second;
        this->windows.erase(window);
    }
}


//Добавить менеджер окон - Add manager window
void Context::AddWindowManager(WindowManager* windowManager)
{
    windowManager->SetContext(this);
    this->windowManagers.insert(std::pair<const std::string, WindowManager*>(windowManager->GetName(), windowManager));
}

//Получить менеджер окон - Get manager window
WindowManager* Context::GetWindowManager(const std::string name) const
{
    std::map<const std::string, WindowManager*>::const_iterator windowmanager = this->windowManagers.find(name);
    if (windowmanager != this->windowManagers.end()) 
    {
        return windowmanager->second;
    }
    else
    {
        return nullptr;
    }
}

//Вырезать менеджер окон - Cut window manager
//Внимание при подобной отвязке менеджера окон, он должен быть привязан к другому контексту, иначе окна внутри него будут продолжать отображаться на старом контексте - Attention when unlinking a window manager like this, it must be linked to another context, otherwise the windows inside will continue to display on the old context
WindowManager* Context::CutWindowManager(const std::string name)
{
    std::map<const std::string, WindowManager*>::iterator windowmanager = this->windowManagers.find(name);
    if (windowmanager != this->windowManagers.end()) 
    {
        this->windowManagers.erase(windowmanager);
        return windowmanager->second;
    }
    else 
    {
        return nullptr;
    }
};

//Удалить менеджер окон - Delete manager window
void Context::DeleteWindowManager(const std::string name)
{
    std::map<const std::string, WindowManager*>::iterator windowmanager = this->windowManagers.find(name);
    if (windowmanager != this->windowManagers.end()) 
    {
        delete windowmanager->second;
        this->windowManagers.erase(windowmanager);
    }
};

//Добавить менеджер форм - Add manager form
void Context::AddFormManager(FormManager* formmanager)
{
    formmanager->SetContext(this);
    this->formManagers.insert(std::pair<const std::string, FormManager*>(formmanager->GetName(), formmanager));
};

//Получить менеджер форм - Get manager form
FormManager* Context::GetFormManager(const std::string name) const
{
    std::map<const std::string, FormManager*>::const_iterator formmanager = this->formManagers.find(name);
    if (formmanager != this->formManagers.end()) 
    {
        return formmanager->second;
    }
    else
    {
        return nullptr;
    }
};

//Вырезать менеджер форм - Cut form manager
//Внимание при подобной отвязке менеджера форм, он должен быть привязан к другому контексту, иначе формы внутри него будут продолжать отображаться на старом контексте - Attention when unlinking a form manager like this, it must be linked to another context, otherwise the forms inside will continue to display on the old context
FormManager* Context::CutFormManager(const std::string name)
{
    std::map<const std::string, FormManager*>::iterator formmanager = this->formManagers.find(name);
    if (formmanager != this->formManagers.end()) 
    {
        this->formManagers.erase(formmanager);
        return formmanager->second;
    }
    else 
    {
        return nullptr;
    }
};

//Удалить менеджер форм - Delete manager form
void Context::DeleteFormManager(const std::string name)
{
    std::map<const std::string, FormManager*>::iterator formmanager = this->formManagers.find(name);
    if (formmanager != this->formManagers.end()) 
    {
        delete formmanager->second;
        this->formManagers.erase(formmanager);
    }
};

void Context::ProcessEvents(bool* running)
{
    *running = Backend::ProcessEvents(this->context, this->keyDownCallback, this->powerSave);
}

void Context::Update()
{
    this->context->Update();
}

void Context::Render()
{
    this->context->Render();
}