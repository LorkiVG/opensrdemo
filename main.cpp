#include <LibDAT.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <FrontEndMain.h>
#include <SDL.h>

namespace fs = boost::filesystem;

using namespace std;

int main(int argc, char* argv[])
{
    string breakp;
    cin >> breakp;
    // Инициализируем логи пути на данном этапе уже инициализированы
    MAINLOG = new LogFile(LOGPATH / fs::path("main.log"));
    MAINLOG->WriteStr("Начало загрузки настроек - Starting loading settings", "\n");

    // Загружаем настройки
    MAINLOG->WriteStr("Настройки успешно загружены - Settings successfully loaded", "\n");
    SETTINGS = new SettingsFile(CFGPATH / fs::path("Settings.ini"));
    MAINLOG->WriteStr("Начало загрузки файлов ресурсов - Starting loading resourses files", "\n");

    LANGPATH = LANGSPATH / fs::path(SETTINGS->GetProperty<string>("Language","current_language","ru"));
    STYLESPATH = LANGPATH / fs::path("styles");
    UIPATH = LANGPATH / fs::path("views");

    // Загружаем датники
    CACHEDATA = new DATFile(CFGPATH / fs::path("CacheData.json"),"CacheData");
    CACHEDATA->Representation();
    MAINDAT = new DATFile(CFGPATH / fs::path("Main.json"),"Main");
    MAINDAT->Representation();

    MAINLOG->WriteStr("Файлы ресурсов успешно загружены - Resourses files successfully loaded", "\n");

    
    
    // Запускаем поток музыки

    // Передаём главный поток во фронтенд
    return FrontendMain();
}