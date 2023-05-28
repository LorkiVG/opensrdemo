#pragma once
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

using namespace std;

//Путь к папке с выходным файлом игры
extern const fs::path MAINPATH;
//Путь к папке с ресурсами игры
extern const fs::path RESPATH;
//Путь к папке с графическими ресурсами игры
extern const fs::path DATAPATH;
//Путь к папке с ресурсами игры
extern const fs::path FONTSPATH;
//Путь к папке с логами
extern const fs::path LOGPATH;
//Путь к папке с текстовыми ресурсами игры
extern const fs::path CFGPATH;
//Путь к папке с языками
extern const fs::path LANGSPATH;
//Путь к папке с текущим выбраным языком, подгружается на этапе загрузки настроек
extern fs::path LANGPATH;
//Путь к папке со стилями относительно выбранного языка
extern fs::path STYLESPATH;
//Путь к папке с rml
extern fs::path UIPATH;