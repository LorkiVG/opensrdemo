#include "Form.h"

class FormManager
{
    private:
        std::string name;
        std::map<std::string, Form*> forms;

    public:
        FormManager(std::string name);
        ~FormManager();

        void Add(Form* form);
        Form* Get(const std::string& path);
        void Remove(const std::string& path); 
        
        std::string GetName();
};