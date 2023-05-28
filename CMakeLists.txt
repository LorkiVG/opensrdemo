cmake_minimum_required(VERSION 3.14)
project(OpenSR)

set(CMAKE_CXX_STANDARD 14)
#Параметры для поддержки кодировки UTF-8 - Params for support charset UTF-8
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=utf-8 -fexec-charset=utf-8")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=utf-8 -fexec-charset=utf-8")

option(Develop "Разработочная сборка - Develop Build" ON)
option(Testing "Тестирование - Testing" ON)
option(FrontEndTesting "Тест фронтенда - Testing FrontEnd" ON)
option(BackEndTesting "Тест бекенда - Testing BackEnd" ON)
option(ModulesTesting "Тест модулей - Testing modules" ON)
set(LibraryDir "" CACHE PATH "Укажите путь к директории с библиотеками - Specify path to the directory with librares")
set(BoostDir "" CACHE STRING "Укажите путь к директории библиотеки Boost относительно LibraryDir (например boost) - Specify path to the directory with Boost library relative to LibraryDir (e. g. boost)")
set(BoostLibsDir "" CACHE STRING "Укажите путь к директории с библиотеками Boost относительно BoostDir (например stage/lib) - Specify path to the directory with Boost libraries relative to BoostDir (e. g. stage/lib)")

configure_file(defines.h.in defines.h)

#Инициализация настроек Boost, да много настроек но это нужная конфигурация, заменять тут нужно только в зависимости от установленного компилятора -mgw12
list(APPEND CMAKE_PREFIX_PATH ${LibraryDir})

set(BOOST_ROOT "${LibraryDir}/${BoostDir}")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/${BoostLibsDir}")
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_COMPILER "-mgw12")
set(Boost_ARCHITECTURE "-x64")
set(Boost_LIB_PREFIX "lib")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_NO_WARN_NEW_VERSIONS ON)


find_package(Boost REQUIRED COMPONENTS filesystem system regex)

if(NOT Boost_FOUND)
    message(FATAL_ERROR " Не найдена библиотека Boost - Cannot find Boost library")
else()
    message(SUCCESS " Boost был успешно найден ${BOOST_LIBRARYDIR} - Boost was successfully found ${BOOST_LIBRARYDIR}")
endif()


include_directories(${Boost_INCLUDE_DIRS})

#Добавление фронтенда и бекенда - Adding frontend and backend 
add_subdirectory(modules)
add_subdirectory(frontend)
add_subdirectory(backend)

add_executable(OpenSRDemo main.cpp)
target_include_directories(OpenSRDemo PUBLIC frontend/inc)
#Параметры компиляции для windows - Params compile for Windows
if(WIN32)
    #Параметры компиляции с параметром разработки - Params compile with option develop 
    if(Develop)
        add_compile_options(-mwindows -Wall -Wextra -g)
    else()
        add_compile_options(-mwindows -O2)
    endif()
else()
    #Параметры компиляции с параметром разработки - Params compile with option develop 
    if(Develop)
        add_compile_options(-Wall -Wextra -g)
    else()
        add_compile_options(-O2)
    endif()
endif()
if(Develop)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()
target_link_libraries(OpenSRDemo ${Boost_LIBRARIES})
link_libraries(${Boost_LIBRARIES})

#Добавление библиотек фронтенда и бекенда в исполняемый файл - Adding libraries frontend and backend to the executable file
target_link_libraries(OpenSRDemo FilePaths)
target_link_libraries(OpenSRDemo LOG)
target_link_libraries(OpenSRDemo ManageSettings)
target_link_libraries(OpenSRDemo DAT)
target_link_libraries(OpenSRDemo Validator)
target_link_libraries(OpenSRDemo Browser)

target_link_libraries(OpenSRDemo frontend)
target_link_libraries(OpenSRDemo backend)