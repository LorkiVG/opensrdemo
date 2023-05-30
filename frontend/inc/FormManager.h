#pragma once
#include "Form.h"

class FormManager
{
    private:
        std::string name;
        std::map<std::string, Form*> forms;
        Context* context;
        void SetContext(Context* context);
    public:
        
        FormManager(const std::string& name);
        ~FormManager();

        Context* GetContext() const;

        void Add(Form* form);
        Form* Get(const std::string& path) const;
        void Remove(const std::string& path); 
        
        std::string GetName() const;
    friend Context;
};