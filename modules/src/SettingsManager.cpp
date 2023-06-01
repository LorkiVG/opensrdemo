#include <SettingsManager.h>



SettingsManager::SettingsManager(const fs::path& filePath)
{
    this->filePath = filePath;
    Load();
}


//Сохранение настроек
void SettingsManager::Save() const 
{
    ini_parser::write_ini(filePath.string(), this->ptree);
}

//Загрузка настроек
void SettingsManager::Load()
{
    ini_parser::read_ini(filePath.string(), this->ptree);
}

//Основной файл настроек
SettingsManager* SETTINGS;