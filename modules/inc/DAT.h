#pragma once
#include <string>
#include <stack>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>
#include "FilePaths.h"
#include "LOG.h"

namespace fs = boost::filesystem;

using boost::property_tree::ptree;

/// @brief DAT объект 
class DAT
{
    private:
        ptree content;
        fs::path path = "";
        std::string name = "";
        
    public:
        /// @brief Инициализация DAT объекта из другого DAT объекта
        /// @param object Другой DAT объект
        void Init(const DAT& object);
        /// @brief Инициализация DAT объека из пути
        /// @param path Путь к DAT файлу
        void Init(const fs::path& path);
        /// @brief Статическая инициализация DAT объекта из другого DAT объекта
        /// @param object1 Инициализируемый документ
        /// @param object2 Другой DAT объект
        static void Init(DAT& object1, const DAT& object2);
        /// @brief Статическая инициализация DAT объекта из пути
        /// @param object Инициализируемый докент
        /// @param path Путь к DAT файлу
        static void Init(DAT& object, const fs::path& path);
        
        /// @brief Конструктор при помощи другого DAT объекта
        /// @param object Другой DAT объект
        DAT(const DAT& object);
        /// @brief Конструктор при помощи другого DAT объекта и также с указанием имени
        /// @param object Другой DAT объект
        /// @param name Имя
        DAT(const DAT& object, const string& name);
        /// @brief Конструктор при помощи другого файла
        /// @param path Путь к другому файлу
        DAT(const fs::path& path);
        /// @brief  Конструктор при помощи другого файла с указанием имени
        /// @param path Путь к другому файлу
        /// @param name Имя
        DAT(const fs::path& path, const string& name);

        //TODO (переписать на write_json)
        /// @brief Вывод в лог(MAINLOG) DAT файла 
        void Representation();

        /// @brief Проверит соответствие DAT файла с другим сравнив их контент (имена могут быть разными)
        bool Compare(const DAT& object) const;
        static bool Compare(const DAT& object1, const DAT& object2);

        /// @brief Инициализирует DAT объект из другого DAT объекта 
        /// @param object Другой DAT объект
        void operator = (DAT& object)
        {
            this->Init(object);
        }

        /// @brief Проверит на соответствие DAT объекта с другим сравнив их контент (имена могут быть разными) (также тут фактически используется метод Compare)
        /// @param object Другой DAT объект
        bool operator == (DAT& object)
        {
            if(this->Compare(object)) return true;
        }

        /// @brief Проверит на не соответствие DAT объекта с другим сравнив их контент (имена могут быть разными) (также тут фактически используется метод Compare)
        /// @param object Другой DAT объект
        bool operator != (DAT& object)
        {
            if(this->Compare(object)) return false;
        }

        /// @brief Слияние двух DAT объектов с возвратом нового DAT объекта
        /// @param object1 Первый объект слияния
        /// @param object2 Второй объект слияния 
        static DAT* Merge(const DAT& object1, const DAT& object2);
        /// @brief Слияние с другим DAT объектом
        /// @param object Другой DAT объект
        void Merge(const DAT& object);
        /// @brief Слиянине c другим DAT файлом который лежит по пути
        /// @param path Путь к DAT файлу
        void Merge(const fs::path& path);

        /// @brief Получить имя 
        /// @return Имя
        const std::string GetName() const;
        /// @brief Установить имя
        /// @param name Имя
        void SetName(string name);

        /// @brief Получить имя из другого документа (Статический метод)
        /// @param object Документ у которого нужно получить имя
        /// @return Имя
        static const std::string GetName(DAT& object);

        //TODO Сделать методы для получения информации из DAT объекта
};

/// @brief Главный файл различных путей 
extern DAT* CACHEDATA;
/// @brief Главный файл различных прочих настроек 
extern DAT* MAINDAT;