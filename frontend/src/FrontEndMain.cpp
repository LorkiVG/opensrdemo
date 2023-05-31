#include "FrontEndMain.h"

int FrontendMain()
{
    int window_width = SETTINGS->GetProperty<int>("Resolution","GameResolutionX", 1024);
	int window_height = SETTINGS->GetProperty<int>("Resolution","GameResolutionY", 768);
    SDL_SetMainReady();

    //!Внимнание в будущем будет перестройка и создание фасада для работы с бекендом(например нужно чтоб удобно запускать на разных мониторах разные окна)
    bool isbackendinitialized  = Backend::Initialize("OpenSRDemo", window_width, window_height, 1, SETTINGS->GetProperty<bool>("Resolution","Fullscreen", false) );
    Rml::SetSystemInterface(Backend::GetSystemInterface());
	Rml::SetRenderInterface(Backend::GetRenderInterface());
    Rml::Initialise();

	
	ContextManager* contextManager = new ContextManager("main");
	Context* context = new Context("main", window_width, window_height);
	contextManager->Add(context);

	//Добавляем главное окно и менеджер форм в контекст
	context->AddWindow(mainWindow);
	context->AddFormManager(mainFormManager);

	//!Внимание задание роутера тут времено для демки 3 июня в будущем планируется переделка
	router->AddRoute(fs::path("MainMenu.rml"), make_unique<MainMenuControllerFactory>());
	router->AddRoute(fs::path("Settings.rml"), make_unique<SettingsControllerFactory>());


	//!Внимание такая инициализация дебагера временна
	//TODO Переделать и сделать обёртку над дебаггером, и также в будущем избавится от Get так ка это противоречит инкапсуляции
	//Инициализируеим дебагер
	Rml::Debugger::Initialise(context->Get());
	

	//!Внимание такой инит шрифта временный в будущем каждый контроллер будет иметь свой FontsManager
	//TODO Сделать Fonts manager
	//Загрузка основного шрифта
    Rml::LoadFontFace(fs::path(FONTSPATH / fs::path("boucle.otf")).string());
	
	router->GetRoute(fs::path("MainMenu.rml"))->Initialize();

    bool running = true;
    while (running)
    {
		
		contextManager->ProcessEventsAll(&running);
        contextManager->UpdateAll();

		//TODO! Пофиксить этот лютый временный костыль с дефокусирвокой главного окна перед рендером 
		context->UnfocusDocument(mainWindow->GetCurrentView());

		Backend::BeginFrame();
		contextManager->RenderAll();
		Backend::PresentFrame();
    }

	delete contextManager;
    Rml::Shutdown();
    Backend::Shutdown();
    return 0;
}