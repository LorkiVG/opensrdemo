#include "Window.h"

class WindowManager
{
    private:
        std::string name;
        std::map<std::string, Window*> windows;

    public:
        WindowManager(std::string name);
        ~WindowManager();

        void Add(Window* window);
        Window* Get(const std::string& name);
        void Remove(const std::string& name);
        
        std::string GetName();
};
