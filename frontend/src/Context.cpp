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


void Context::AddWindowManager(WindowManager* windowmanager)
{
    windowmanagers[windowmanager->GetName()] = windowmanager;
};

WindowManager* Context::GetWindowManager(const std::string name)
{
    std::map<const std::string, WindowManager*>::const_iterator windowmanager = this->windowmanagers.find(name);
    if (windowmanager != this->windowmanagers.end()) 
    {
        return windowmanager->second;
    }
};

void Context::RemoveWindowManager(const std::string name)
{
    std::map<const std::string, WindowManager*>::iterator windowmanager = this->windowmanagers.find(name);
    if (windowmanager != this->windowmanagers.end()) 
    {
        delete windowmanager->second;
        this->windowmanagers.erase(windowmanager);
    }
};


void Context::AddFormManager(FormManager* formmanager)
{
    formmanagers[formmanager->GetName()] = formmanager;
};

FormManager* Context::GetFormManager(const std::string name)
{
    std::map<const std::string, FormManager*>::const_iterator formmanager = this->formmanagers.find(name);
    if (formmanager != this->formmanagers.end()) 
    {
        return formmanager->second;
    }
};

void Context::RemoveFormManager(const std::string name)
{
    std::map<const std::string, FormManager*>::iterator formmanager = this->formmanagers.find(name);
    if (formmanager != this->formmanagers.end()) 
    {
        delete formmanager->second;
        this->formmanagers.erase(formmanager);
    }
};