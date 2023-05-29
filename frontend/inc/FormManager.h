#pragma once
#include "Form.h"

class FormManager
{
    private:
        std::string name;
        Context* context;
        std::map<std::string, Form*> forms;

    public:
        FormManager(const std::string& name);
        ~FormManager();

        void SetContext(Context* context);
        Context* GetContext() const;

        void Add(Form* form);
        Form* Get(const std::string& path) const;
        void Remove(const std::string& path); 
        
        std::string GetName() const;
};