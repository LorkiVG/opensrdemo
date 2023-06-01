#pragma once
#include "controllers/Controller.h"

class SettingsController : public BaseController {
    public:
        void Initialize() override;
};


class SettingsControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};