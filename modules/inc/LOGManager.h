#pragma once
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
using namespace std;

/// @brief LOG объект
class LOG
{   
    private:
        fs::path path;

    public:
        /// @brief Конструктор LOG объекта по пути
        /// @param path Путь к LOG файлу
        LOG(fs::path path);
        /// @brief Вывести в лог строку 
        /// @param str Строка
        void WriteStr(string str); 
        /// @brief Вывести в лог строку со своим окончанием
        /// @param str Строка
        /// @param end Своё окончание строки
        void WriteStr(string str, string end);           
};

//TODO! Подумать как оформить эту функцию нормально
/// @brief Сделать нужный отступ в табах
/// @param level Уровень отступа (количество отступаемых табов)
string Indent(int level);

extern LOG* MAINLOG;