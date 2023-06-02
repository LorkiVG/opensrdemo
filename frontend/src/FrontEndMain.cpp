#include "FrontEndMain.h"
#include "RouterManager.h"

int FrontendMain()
{
    int window_width = SETTINGS->GetProperty<int>("Resolution","GameResolutionX", 1024);
	int window_height = SETTINGS->GetProperty<int>("Resolution","GameResolutionY", 768);
    SDL_SetMainReady();

    //!Внимнание в будущем будет перестройка и создание фасада для работы с бекендом
    Backend::Initialize("OpenSRDemo", window_width, window_height, 1, SETTINGS->GetProperty<bool>("Resolution","Fullscreen", false),SETTINGS->GetProperty<bool>("Resolution","Windowed", false));
    Rml::SetSystemInterface(Backend::GetSystemInterface());
	Rml::SetRenderInterface(Backend::GetRenderInterface());
    Rml::Initialise();

	
	mainContextManager = new ContextManager("main");
	mainContext = new Context("main", window_width, window_height);
	mainContextManager->Add(mainContext);

	//Добавляем главное окно и менеджер форм в контекст
	mainContext->AddWindow(mainWindow);
	mainContext->AddFormManager(mainFormManager);

	//!Внимание задание роутера тут времено для демки 3 июня в будущем планируется переделка
	mainRouter->AddRoute(fs::path("MainMenu.rml"), make_unique<MainMenuControllerFactory>());
	mainRouter->AddRoute(fs::path("Preloader.rml"), make_unique<PreloaderControllerFactory>());
	mainRouter->AddRoute(fs::path("Settings.rml"), make_unique<SettingsControllerFactory>());

	//!Внимание такая инициализация дебагера временна
	//TODO Переделать и сделать обёртку над дебаггером, и также в будущем избавится от Get так ка это противоречит инкапсуляции
	//Инициализируеим дебагер
	Rml::Debugger::Initialise(mainContext->Get());
	
	//!Временно создаём прелоадер тут, планирую перестроить это после первой демки
	std::unique_ptr<BaseController> basePtr = make_unique<PreloaderControllerFactory>()->Create();
	PreloaderController* preloaderPtr = dynamic_cast<PreloaderController*>(basePtr.get());
	if (preloaderPtr != nullptr) {
		basePtr.release(); 
		mainPreloader.reset(preloaderPtr);
		preloaderPtr = nullptr;
	}
	mainPreloader->Initialize();

	//!Внимание такой инит шрифта временный в будущем каждый контроллер будет иметь свой FontsManager
	//TODO Сделать Fonts manager
	//Загрузка основного шрифта
    Rml::LoadFontFace(fs::path(FONTSPATH / fs::path("boucle.otf")).string());
	
	mainRouter->GetRoute(fs::path("MainMenu.rml"))->Initialize();

    bool running = true;
    while (running)
    {
		mainContextManager->ProcessEventsAll(&running);
        mainContextManager->UpdateAll();
		
		//TODO! Пофиксить этот лютый временный костыль с дефокусирвокой главного окна перед рендером 
		mainContext->UnfocusDocument(mainWindow->GetCurrentView());
		
		Backend::BeginFrame();
		mainContextManager->RenderAll();
		Backend::PresentFrame();
    }

	delete mainContextManager;
    Rml::Shutdown();
    Backend::Shutdown();
    return 0;
}