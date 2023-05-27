#include "controllers/Preloader.h"

void PreloaderController::Initialize(const fs::path name) 
{
    
};

std::unique_ptr<BaseController> PreloaderControllerFactory::Create()
{
    return std::make_unique<PreloaderController>();
}