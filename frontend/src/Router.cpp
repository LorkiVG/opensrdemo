#include <Router.h>


void Router::AddRoute(const fs::path path, std::unique_ptr<BaseControllerFactory> factory) 
{
    factories[path] = std::move(factory);
}

void Router::RemoveRoute(const fs::path path) 
{
    factories.erase(path);
}

std::unique_ptr<BaseController> Router::GetRoute(const fs::path path) 
{
    auto it = factories.find(path);
    if (it != factories.end()) 
    {
        return it->second->Create();
    } 
    else 
    {
        return nullptr;
    }        
};

std::string Router::GetName()
{
    return this->name;
}