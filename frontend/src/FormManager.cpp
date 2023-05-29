#include <modules/inc/FilePaths.h>
#include <FormManager.h>

FormManager::FormManager(const std::string&)
{
    this->name = name;
};

FormManager::~FormManager()
{
    for(std::map<const std::string, Form*>::iterator form = this->forms.begin(); form != this->forms.end();)
    {
        delete form->second;
        forms.erase(form);
    }
};

// Добавить форму
void FormManager::Add(Form* form)  
{
    this->forms[form->GetName()] = form;
}

// Получить форму
Form* FormManager::Get(const std::string& name) const
{
    std::map<const std::string, Form*>::const_iterator form = this->forms.find(name);
    if (form != this->forms.end()) 
    {
        return form->second;
    }
    else
    {
        return nullptr;
    }
}

// Удалить форму
void FormManager::Remove(const std::string& name) 
{
    std::map<const std::string, Form*>::iterator form = this->forms.find(name);
    if (form != this->forms.end()) 
    {
        delete form->second;
        this->forms.erase(form);
    }
}

std::string FormManager::GetName() const
{
    return this->name;
};