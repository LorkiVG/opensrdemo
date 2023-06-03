#pragma once
#include "controllers/Controller.h"
#include "Context.h"


class PreloaderController : public BaseController {
    private:
        Window* preloaderWindow;
        Rml::Element* preloaderBarStrip;
        //!Внимание такое объявление временно 
        std::thread timerHideThread; 
    public:
        void Initialize() override;

        Window* GetPreloaderWindow();

        void Show();
        void UpdatePreloader(int percent);
        void Hide();
};


class PreloaderControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};

extern std::unique_ptr<PreloaderController> mainPreloader;