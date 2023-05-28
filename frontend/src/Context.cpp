#include "Context.h"

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

//TODO Да-да нарушаю приницип единой ответсвенности и создаю View в классе Context, но это чисто потому-что RmlUI сами его нарушили, в идеале это переписать
//И вообще желательно этот метод убрать.И сделать загрузку в самом View

//Загружает представление из файла
View* Context::LoadDocument(const fs::path& path)
{
    View* view = (View*)Rml::Context::LoadDocument(path.string());
    return view;
}

//Добавить менеджер окон - Add manager window
void Context::AddWindowManager(WindowManager* windowmanager)
{
    MAINLOG->WriteStr(windowmanager->GetName(),"\n");
    std::string name = windowmanager->GetName();
    MAINLOG->WriteStr("test","\n");
    string size = to_string(this->windowmanagers.size());
    MAINLOG->WriteStr(size,"\n");
    this->windowmanagers.insert(std::pair<const std::string, WindowManager*>(name, windowmanager));
    MAINLOG->WriteStr(windowmanager->GetName(),"\n");
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