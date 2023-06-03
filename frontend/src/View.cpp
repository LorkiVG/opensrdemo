#include "View.h"
#include "Window.h"
#include "ContextManager.h"

View::View(const std::string& name)
{
    this->window = nullptr;
};

View::~View()
{
    this->view->Close();
    delete this->view;
}


void View::SetWindow(Window* window)
{
    this->window = window;
}


Context* View::GetContext()
{
    return this->window->GetContext();
}

Rml::Element* View::GetElementById(const std::string& id)
{
    return this->view->GetElementById(id);
}

void View::GetElementsByTagName(Rml::ElementList& elements, const std::string& tag)
{
    this->view->GetElementsByTagName(elements, tag);
}

void View::AddEventListener(const Rml::String& event, Rml::EventListener* listener, bool in_capture_phase)
{
    this->view->AddEventListener(event, listener, in_capture_phase);
}


void View::PullToFront()
{
    this->view->PullToFront();
}

void View::PushToBack()
{
    this->view->PushToBack();
}

bool View::SetProperty(Rml::PropertyId id, const Rml::Property& property)
{
    this->view->SetProperty(id, property);
}

void View::Load(fs::path path)
{
    Context* context = this->GetContext();
    if(context != nullptr)
    {
        this->view = context->LoadDocument(path);
        Rml::ElementList imgElements;
        this->view->GetElementsByTagName(imgElements, "img");
        for (auto& element : imgElements)
        {
            if (element->HasAttribute("src"))
            {
                string srcAttribute = element->GetAttribute("src")->Get<string>();
                boost::replace_all(srcAttribute, "{RESPATH}", RESPATH.string());
                boost::replace_all(srcAttribute, "{UIPATH}", UIPATH.string());
                boost::replace_all(srcAttribute, "{DATAPATH}", DATAPATH.string());
                boost::replace_all(srcAttribute, "{STYLESPATH}", STYLESPATH.string());
                element->SetAttribute("src", srcAttribute);
            }
        }
    }
}

void View::Show(Rml::ModalFlag modalFlag, Rml::FocusFlag focusFlag)
{
    this->view->Show(modalFlag, focusFlag);
}

void View::Hide()
{
    this->view->Hide();
}

void View::Close()
{
    this->view->Close();
}

