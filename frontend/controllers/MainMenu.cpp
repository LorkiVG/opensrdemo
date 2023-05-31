#include <controllers/MainMenu.h>

class MainMainControllerEventHandler : public Rml::EventListener
{
public:
    virtual void ProcessEvent(Rml::Event& event)
    {
        if (event == "click")
        {
            // обработка клика
        }
    }
};


void MainMenuController::Initialize() 
{
    View* view = new View("mainmenu");
	mainWindow->SetCurrentView(view);
	view->Load(fs::path(UIPATH / fs::path("mainmenu.rml")));
    Rml::ElementList imgElements;
	view->GetElementsByTagName(imgElements, "img");
	for (auto& element : imgElements)
	{
		if (element->HasAttribute("src"))
		{
			string srcAttribute = element->GetAttribute("src")->Get<string>();
			boost::replace_all(srcAttribute, "{RESPATH}", RESPATH.string());
			boost::replace_all(srcAttribute, "{DATAPATH}", DATAPATH.string());
			element->SetAttribute("src", srcAttribute);
		}
	}
	view->Show();
};
std::unique_ptr<BaseController> MainMenuControllerFactory::Create() 
{
    return std::make_unique<MainMenuController>();
};