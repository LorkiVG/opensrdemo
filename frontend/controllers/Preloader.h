#pragma once
#include "controllers/Controller.h"

class PreloaderController : public BaseController {
    public:
        void Initialize() override;
};


class PreloaderControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};
