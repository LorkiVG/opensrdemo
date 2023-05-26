#include <LibPaths.h>

namespace fs = boost::filesystem;

using namespace std;

const fs::path MAINPATH = fs::canonical(".");
const fs::path RESPATH = MAINPATH / fs::path("resources");
const fs::path DATAPATH = RESPATH / fs::path("DATA");
const fs::path FONTSPATH = DATAPATH / fs::path("fonts");
const fs::path LOGPATH = MAINPATH / fs::path("logs");
const fs::path CFGPATH = RESPATH / fs::path("CFG");
const fs::path LANGSPATH = CFGPATH / fs::path("langs");
fs::path LANGPATH = LANGSPATH / fs::path("ru");
fs::path UIPATH = LANGPATH / fs::path("views");
fs::path STYLESPATH = CFGPATH / fs::path("styles");