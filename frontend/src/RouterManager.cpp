#include "RouterManager.h"


RouterManager::RouterManager(std::string name)
{
    
}

RouterManager::~RouterManager()
{
    for(std::map<const std::string, Router*>::iterator router = this->routers.begin(); router != this->routers.end();)
    {
        delete router->second;
        routers.erase(router);
    };
}

void RouterManager::Add(Router* window)
{
    
}

Router* RouterManager::Get(const std::string& name)
{
    
}

void RouterManager::Remove(const std::string& name)
{
    
}

std::string RouterManager::GetName()
{
    
}
