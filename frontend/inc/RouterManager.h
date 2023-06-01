#pragma once
#include "modules/inc/LOGManager.h"
#include "Router.h"

class RouterManager
{
    private:
        std::string name;
        std::map<std::string, Router*> routers;

    public:
        RouterManager(const std::string& name);
        ~RouterManager();

        void Add(Router* router);
        Router* Get(const std::string& name) const;
        void Remove(const std::string& name);
        
        std::string GetName() const;
};


extern RouterManager* routerManager;
extern Router* router;
