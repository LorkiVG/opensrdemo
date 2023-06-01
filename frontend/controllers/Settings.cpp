#include "controllers/Settings.h"


void SettingsController::Initialize() 
{
    Form* form = new Form("settings");
    mainFormManager->Add(form);

    form->Load(fs::path(UIPATH / fs::path("Settings.rml")));

    form->Show();
};

std::unique_ptr<BaseController> SettingsControllerFactory::Create() {
    return std::make_unique<SettingsController>();
}