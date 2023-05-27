#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "FilePaths.h"


using namespace std;

namespace fs = boost::filesystem;
namespace ini_parser = boost::property_tree::ini_parser;

class SettingsFile 
{
    private:
        void Load();
        fs::path filePath;
        boost::property_tree::ptree ptree;

    public:
        SettingsFile(const fs::path& filePath);

        template<typename generic>
        generic GetProperty(string section, string key, generic defaultvalue)
        {
            try 
            {
                return this->ptree.get<generic>(section + "." + key);
            } 
            catch (const boost::property_tree::ptree_error&) 
            {
                return defaultvalue;
            }
        }

        template<typename generic>
        void SetProperty(const string& section, const string& key, const generic& value) 
        {
            this->ptree.put(section + "." + key, value);
        }

        void Save() const;
};

extern SettingsFile* SETTINGS;