#pragma once
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

using namespace std;

/// @brief Путь к папке с выходным файлом игры
extern const fs::path MAINPATH;
/// @brief Путь к папке с ресурсами игры
extern const fs::path RESPATH;
/// @brief Путь к папке с графическими ресурсами игры
extern const fs::path DATAPATH;
/// @brief Путь к папке с ресурсами игры
extern const fs::path FONTSPATH;
/// @brief Путь к папке с логами
extern const fs::path LOGPATH;
/// @brief Путь к папке с текстовыми ресурсами игры
extern const fs::path CFGPATH;
/// @brief Путь к папке с языками
extern const fs::path LANGSPATH;
/// @brief Путь к папке с текущим выбраным языком, подгружается на этапе загрузки настроек
extern fs::path LANGPATH;
/// @brief Путь к папке со стилями относительно выбранного языка
extern fs::path STYLESPATH;
/// @brief Путь к папке с rml 
extern fs::path UIPATH;