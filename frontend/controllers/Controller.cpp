#include <controllers/Controller.h>

BaseController::~BaseController() = default;
void BaseController::Initialize() 
{
    
};

BaseControllerFactory::~BaseControllerFactory() = default;
std::unique_ptr<BaseController> BaseControllerFactory::Create()
{
    return std::make_unique<BaseController>();
};

Window* mainWindow = new Window("main");
FormManager* mainFormManager = new FormManager("main");