#include <LibPaths.h>
#include <FormManager.h>

FormManager::FormManager(std::string name)
{
    this->name = name;
};

FormManager::~FormManager()
{
    for(std::map<const std::string, Form*>::iterator form = this->forms.begin(); form != this->forms.end();)
    {
        form->second->Close();
        delete form->second;
        forms.erase(form);
    }
};


// Добавить форму
void FormManager::Add(Form* form)  
{
    this->forms[form->GetTitle()] = form;
}

// Получить форму
Form* FormManager::Get(const std::string& name) 
{
    std::map<const std::string, Form*>::const_iterator form = this->forms.find(name);
    if (form != this->forms.end()) 
    {
        return form->second;
    }
}

// Удалить форму
void FormManager::Remove(const std::string& name) 
{
    std::map<const std::string, Form*>::iterator form = this->forms.find(name);
    if (form != this->forms.end()) 
    {
        form->second->Close();
        delete form->second;
        this->forms.erase(form);
    }
}

std::string FormManager::GetName() 
{
    return name;
};