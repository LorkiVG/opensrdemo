#pragma once
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
using namespace std;


class LogFile
{   
    private:
        fs::path path;

    public:
        LogFile(fs::path path);
        void WriteStr(string str); 
        void WriteStr(string str, string end);           
};

string Indent(int level);

extern LogFile* MAINLOG;