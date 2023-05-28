#include "Context.h"

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


Context::Context(std::string name, int width, int height, KeyDownCallback keyDownCallback = nullptr, bool  )
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
}

Context::~Context() 
{
    for(std::map<const std::string, FormManager*>::iterator formmanager = formmanagers.begin(); formmanager != formmanagers.end();)
    {
        delete formmanager->second;
        formmanagers.erase(formmanager);
    }
    for(std::map<const std::string, WindowManager*>::iterator windowmanager = windowmanagers.begin(); windowmanager != windowmanagers.end();)
    {
        delete windowmanager->second;
        windowmanagers.erase(windowmanager);
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




//KeyDown Events Callbacks
KeyDownCallback Context::GetKeyDownCallback()
{
    return this->keyDownCallback;
}

void Context::SetKeyDownCallback(KeyDownCallback keyDownCallback)
{
    this->keyDownCallback = keyDownCallback;
}


//Добавить менеджер окон - Add manager window
void Context::AddWindowManager(WindowManager* windowmanager)
{
    this->windowmanagers.insert(std::pair<const std::string, WindowManager*>(windowmanager->GetName(), windowmanager));
}

//Получить менеджер окон - Get manager window
WindowManager* Context::GetWindowManager(const std::string name) const
{
    std::map<const std::string, WindowManager*>::const_iterator windowmanager = this->windowmanagers.find(name);
    if (windowmanager != this->windowmanagers.end()) 
    {
        return windowmanager->second;
    }
    else
    {
        return nullptr;
    }
}

//Удалить менеджер окон - Delete manager window
void Context::RemoveWindowManager(const std::string name)
{
    std::map<const std::string, WindowManager*>::iterator windowmanager = this->windowmanagers.find(name);
    if (windowmanager != this->windowmanagers.end()) 
    {
        delete windowmanager->second;
        this->windowmanagers.erase(windowmanager);
    }
};

//Добавить менеджер форм - Add manager form
void Context::AddFormManager(FormManager* formmanager)
{
    this->formmanagers.insert(std::pair<const std::string, FormManager*>(formmanager->GetName(), formmanager));
    formmanagers[formmanager->GetName()] = formmanager;
};

//Получить менеджер форм - Get manager form
FormManager* Context::GetFormManager(const std::string name) const
{
    std::map<const std::string, FormManager*>::const_iterator formmanager = this->formmanagers.find(name);
    if (formmanager != this->formmanagers.end()) 
    {
        return formmanager->second;
    }
    else
    {
        return nullptr;
    }
};

//Удалить менеджер форм - Delete manager form
void Context::RemoveFormManager(const std::string name)
{
    std::map<const std::string, FormManager*>::iterator formmanager = this->formmanagers.find(name);
    if (formmanager != this->formmanagers.end()) 
    {
        delete formmanager->second;
        this->formmanagers.erase(formmanager);
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