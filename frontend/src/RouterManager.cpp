#include "RouterManager.h"


RouterManager::RouterManager(const std::string& name)
{
    this->name = name;
}

RouterManager::~RouterManager()
{
    for(std::map<const std::string, Router*>::iterator router = this->routers.begin(); router != this->routers.end(); ++router)
    {
        delete router->second;
        routers.erase(router);
    };
}

void RouterManager::Add(Router* router)
{
    this->routers[router->GetName()] = router;
}

Router* RouterManager::Get(const std::string& name) const
{
    std::map<const std::string, Router*>::const_iterator router = this->routers.find(name);
    if (router != this->routers.end()) 
    {
        return router->second;
    }
    else
    {
        return nullptr;
    }
}

void RouterManager::Remove(const std::string& name)
{
    std::map<const std::string, Router*>::iterator router = this->routers.find(name);
    if (router != this->routers.end()) 
    {
        delete router->second;
        this->routers.erase(router);
    }
}

std::string RouterManager::GetName() const
{
    return this->name;
}
