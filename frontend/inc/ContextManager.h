#pragma once
#include "Context.h"

class ContextManager
{
    private:
        std::string name;
        std::map<const std::string, Context*> contexts;

    public:
        ContextManager(std::string name);
        ~ContextManager();

        void Add(Context* context);
        Context* Get(const std::string name) const;
        void Remove(const std::string name);
        
        std::string GetName() const;
};