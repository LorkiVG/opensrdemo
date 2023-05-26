#include <string>
#include <memory>
#include "WindowManager.h"
#include "Controller.h"




class MainMenuController : public BaseController {
    private:
        Rml::ElementDocument* window;
    public:
        void Initialize(WindowManager* windowManager, const fs::path name);
        
};


class MainMenuControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};

namespace MainMenuControllerValidator {
    bool ButtonsValidator(const std::string& input);
};