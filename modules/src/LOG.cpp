#include <LOG.h>

LogFile::LogFile(fs::path path)
{
    this->path = path;
    // Проверяем существование файла
    ofstream log(this->path.string());
    log << "Старт - Start\n";
    log.close();
};
void LogFile::WriteStr(string str) 
{
    ofstream log(this->path.string(), ios::app);
    log << str;
    log.close();
};
void LogFile::WriteStr(string str, string end) 
{
    ofstream log(this->path.string(), ios::app);
    log << str << end;
    log.close();
};
string Indent(int level) 
{
    string s; 
    for (int i=0; i < level; i++) s += "    ";
    return s; 
};


LogFile* MAINLOG;