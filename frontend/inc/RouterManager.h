#pragma once
#include "Router.h"

class RouterManager
{
    private:
        std::string name;
        std::map<std::string, Router*> routers;

    public:
        RouterManager(std::string name);
        ~RouterManager();

        void Add(Router* router);
        Router* Get(const std::string& name) const;
        void Remove(const std::string& name);
        
        std::string GetName() const;
};

