#include "controllers/Settings.h"


void SettingsController::Initialize(const fs::path name) 
{
    
};

std::unique_ptr<BaseController> SettingsControllerFactory::Create() {
    return std::make_unique<SettingsController>();
}