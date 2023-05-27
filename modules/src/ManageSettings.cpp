#include <ManageSettings.h>



SettingsFile::SettingsFile(const fs::path& filePath)
{
    this->filePath = filePath;
    Load();
}


//Сохранение настроек
void SettingsFile::Save() const 
{
    ini_parser::write_ini(filePath.string(), this->ptree);
}

//Загрузка настроек
void SettingsFile::Load()
{
    ini_parser::read_ini(filePath.string(), this->ptree);
}

//Основной файл настроек
SettingsFile* SETTINGS;