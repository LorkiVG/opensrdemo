#include "controllers/Preloader.h"

void PreloaderController::Initialize() 
{
    
};

std::unique_ptr<BaseController> PreloaderControllerFactory::Create()
{
    return std::make_unique<PreloaderController>();
}