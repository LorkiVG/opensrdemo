#include "Form.h"
#include "FormManager.h"
#include "Context.h"

Form::Form(const std::string& name) : View(name)
{
    this->name = name;
    this->manager = nullptr;
};

void Form::Load(fs::path path)
{
    if(this->manager != nullptr)
    {
        Context* context = this->manager->GetContext();
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
    
}

void Form::SetManager(FormManager* manager)
{
    this->manager = manager;
}

std::string Form::GetName()
{
    return this->name;
}