#include "View.h"
#include "Window.h"
#include "Context.h"

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


void View::Load(fs::path path)
{
    Context* context = this->GetContext();
    if(context != nullptr)
    {
        this->view = context->LoadDocument(path);
    }
}
void View::Show(Rml::ModalFlag modalFlag, Rml::FocusFlag focusFlag)
{
    this->view->Show(modalFlag, focusFlag);
}
void View::Close()
{
    this->view->Close();
}