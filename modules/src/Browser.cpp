#include "Browser.h"

void OpenBrowser(const std::string& url) {
    std::string command;
    #ifdef _WIN32
        command = "start \"\" \"" + url + "\"";
    #elif __APPLE__
        command = "open " + url;
    #else
        command = "xdg-open " + url;
    #endif

    std::system(command.c_str());
}