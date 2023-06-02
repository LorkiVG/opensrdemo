#pragma once
#include "controllers/Controller.h"
#include "Context.h"


class PreloaderController : public BaseController {
    private:
        Window* preloaderWindow;
    public:
        void Initialize() override;
        void Show();
        void UpdatePreloader();
        void PreHide();
        void Hide();
};


class PreloaderControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};

extern std::unique_ptr<PreloaderController> mainPreloader;