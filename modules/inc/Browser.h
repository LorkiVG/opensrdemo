#pragma once
#include <cstdlib>
#include <string>

//TODO Подумать о создании класса или отдельного пространства имён для взаимодествия с браузером
/// @brief Открывает браузер
/// @param url Ссылка которую надо открыть
void OpenBrowser(const std::string& url);