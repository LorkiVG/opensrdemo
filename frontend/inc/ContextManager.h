#include "Context.h"

class ContextManager
{
    private:
        std::map<const std::string, Context*> contexts;
    public:
        ~ContextManager();
        void Add(Context* context);

        Context* Get(const std::string name) const;
        void Remove(const std::string name);
        
};