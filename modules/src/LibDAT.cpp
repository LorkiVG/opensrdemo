#include <LibDAT.h>

//Инициализация
void DATFile::Init(const DATFile& document) 
{
    this->content = document.content;
}
void DATFile::Init(const fs::path& path)
{
    boost::property_tree::read_json(path.string(), this->content);
    this->path = path;
    this->name = this->path.stem().string();
}
void DATFile::Init(DATFile& document1, const DATFile& document2) 
{
    document1.content = document2.content;
}
void DATFile::Init(DATFile& document, const fs::path& path) 
{
    boost::property_tree::read_json(path.string(), document.content);
    document.path = path;
    document.name = document.path.stem().string();
}

//Инициализация при помощи конструктора
DATFile::DATFile(const DATFile& document) {
    this->Init(document);
};
DATFile::DATFile(const DATFile& document, const string& name) 
{
    this->Init(document);
    this->name = name;
};

DATFile::DATFile(const fs::path& path) 
{
    this->Init(path);
};
DATFile::DATFile(const fs::path& path, const string& name) 
{
    this->Init(path);
    this->name = name;
};

//Вывод в лог DAT файла (переписать на write_json)
void DATFile::Representation()
{
    // Определите элемент стека как tuple из итератора, конечного итератора, узла и уровня вложенности
    using StackItem = std::tuple<boost::property_tree::ptree::iterator, boost::property_tree::ptree::iterator, boost::property_tree::ptree*, int>;

    std::stack<StackItem> stack;

    // Если контент не пуст, то добавляем первый элемент (корень дерева) в стек
    if (!this->content.empty())
    {
        stack.push(StackItem(this->content.begin(), this->content.end(), &this->content, 0));
    }

    // Цикл выполняется, пока стек не пуст
    while (!stack.empty())
    {
        // Получаем верхний элемент стека
        StackItem& top = stack.top();

        // Извлекаем данные из кортежа
        ptree::iterator it = std::get<0>(top);  // текущий итератор
        ptree::iterator end = std::get<1>(top);  // конечный итератор
        ptree* pt = std::get<2>(top);  // текущий узел
        int current_level = std::get<3>(top);  // текущий уровень вложенности

        // Если текущий итератор равен началу, то выводим открывающую скобку
        if (it == pt->begin())
        {
            MAINLOG->WriteStr("{\n");
        }

        // Если текущий итератор не равен концу, то обрабатываем узел
        if (it != end)
        {
            // Выводим ключ узла
            MAINLOG->WriteStr(Indent(current_level + 1) + "\"" + it->first + "\": ");
            
            // Если узел не содержит дочерних элементов, то выводим его значение
            if (it->second.empty())
            {
                MAINLOG->WriteStr("\"" + it->second.data() + "\"");
            }
            else  // Если узел содержит дочерние элементы, то добавляем их в стек
            {
                stack.push(StackItem(it->second.begin(), it->second.end(), &(it->second), current_level + 1));
                continue;
            }

            // Если следующий элемент существует, то добавляем запятую
            if (++std::get<0>(top) != end)
            {
                MAINLOG->WriteStr(",");
            }

            // Переходим на новую строку
            MAINLOG->WriteStr("\n");
        }
        else  // Если текущий итератор достиг конца, то закрываем узел
        {
            // Выводим закрывающую скобку
            MAINLOG->WriteStr(Indent(current_level) + "}");

            // Удаляем обработанный элемент из стека
            stack.pop();

            // Если стек не пуст, идёт проверка на следующий элемент и, если это не последний элемент, добавляем запятую
            if (!stack.empty())
            {
                StackItem& topParent = stack.top();
                if (++std::get<0>(topParent) != std::get<1>(topParent))
                {
                    MAINLOG->WriteStr(",");
                }

                // Переход на новую строку
                MAINLOG->WriteStr("\n");
            }
        }
    }
    MAINLOG->WriteStr("\n");
};

//Сравнение двух загруженных DAT файлов
bool DATFile::Compare(const DATFile& document) const {
    if (document.content == content) return true;
};
bool DATFile::Compare(const DATFile& document1, const DATFile& document2) {
    if (document1.content == document2.content) return true;
};


//TODO Написать мердж методы
//Слияние DAT файлов
DATFile* DATFile::Merge(const DATFile& document1, const DATFile& document2) 
{
    DATFile* out = new DATFile(document1);
    return out;
};
void DATFile::Merge(const DATFile& document2) {
    
};
void DATFile::Merge(const fs::path& path) {
    
};



const std::string DATFile::GetName(DATFile& document) const 
{
    return document.name;
};

void DATFile::SetName(const DATFile& document) 
{
    this->name = document.name;
};

void DATFile::SetName(string name) 
{
    this->name = name;
};


DATFile* CACHEDATA;
DATFile* MAINDAT;