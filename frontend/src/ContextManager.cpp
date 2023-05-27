#include "ContextManager.h"

ContextManager::ContextManager(const std::string& name) 
{
    this->name = name;
}

ContextManager::~ContextManager()
{
    for(std::map<const std::string, Context*>::iterator context = this->contexts.begin(); context != this->contexts.end();)
    {
        delete context->second;
        contexts.erase(context);
    }
};

void ContextManager::Add(Context* context)
{
    this->contexts[context->GetName()] = context;
};

Context* ContextManager::Get(const std::string& name) const
{
    std::map<const std::string, Context*>::const_iterator context = this->contexts.find(name);
    if (context != this->contexts.end()) 
    {
        return context->second;
    }
};
void ContextManager::Remove(const std::string& name)
{
    std::map<const std::string, Context*>::iterator context = this->contexts.find(name);
    if (context != this->contexts.end()) 
    {
        delete context->second;
        this->contexts.erase(context);
    }
};

std::string ContextManager::GetName() const
{
    return this->name;
};