#include <string>
#include <stack>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>
#include "LibPaths.h"
#include "LibLOG.h"

namespace fs = boost::filesystem;

using boost::property_tree::ptree;

class DATFile
{
    private:
        ptree content;
        fs::path path = "";
        std::string name = "";
        
    public:
        //Инициализация
        void Init(const DATFile& document);
        void Init(const fs::path& path);
        static void Init(DATFile& document1, const DATFile& document2);
        static void Init(DATFile& document, const fs::path& path);
        
        //Инициализация при помощи конструктора
        DATFile(const DATFile& document);
        DATFile(const DATFile& document, const string& name);
        DATFile(const fs::path& path);
        DATFile(const fs::path& path, const string& name);

        //Вывод в лог DAT файла (переписать на write_json)
        void Representation();

        //Сравнение двух загруженных DAT файлов
        bool Compare(const DATFile& document) const;
        static bool Compare(const DATFile& document1, const DATFile& document2);

        void operator = (DATFile& document)
        {
            this->Init(document);
        }

        bool operator == (DATFile& document)
        {
            if(this->Compare(document)) return true;
        }

        bool operator != (DATFile& document)
        {
            if(this->Compare(document)) return false;
        }

        //Слияние DAT файлов
        static DATFile* Merge(const DATFile& document1,const DATFile& document2);

        //Слияние с другим DAT файлом
        void Merge(const DATFile& document);
        void Merge(const fs::path& path);

        const std::string GetName(DATFile& document) const;

        void SetName(const DATFile& document);
        void SetName(string name);
};

//Главный файл различных путей 
extern DATFile* CACHEDATA;
//Главный файл различных прочих настроек 
extern DATFile* MAINDAT;