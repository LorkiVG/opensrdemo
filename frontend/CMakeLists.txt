cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)


#Подключение библиотеки Boost к целям в текущем проекте
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

#Библиотека для более удобной работы с графикой и цветами
#TODO Занятся библиотекой в будущем
add_library(LibGraphics STATIC src/modules/LibGraphics.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)


file(GLOB LibGraphics_SOURCES inc/modules/LibGraphics.cpp)

target_sources(LibGraphics PUBLIC
    ${LibGraphics_SOURCES}
)

target_include_directories(LibGraphics PUBLIC inc/modules)
#TODO Написать нормальный поиск библиотеки RmlUI
#Библиотека фронтенда
set(RmlUiDir "" CACHE STRING "Укажите путь к вашей директории библиотеки RmlUI(например RmlUi) относительно указаного пути в LibraryDir - Specify path to the directory with RmlUi library relative to LibraryDir (e. g. RmlUi)")
set(RmlUiPath ${LibraryDir}/${RmlUiDir})
set(RmlUiBuildPath ${RmlUiPath}/Build)
set(RmlUiIncludePath ${RmlUiPath}/Include)
set(RmlUiBackendsPath ${CMAKE_CURRENT_SOURCE_DIR}/Backends)


set(HarfBazzDir "" CACHE STRING "Укажите путь к вашей директории библиотеки HarfBazz(например harfbuzz-7.3.0) относительно указаного пути в LibraryDir - Specify path to the directory with HarfBazz library relative to LibraryDir (e. g. harfbuzz-7.3.0)")
set(HarfBazzPath ${LibraryDir}/${HarfBazzDir})
set(HarfBazzDir ${RmlUiPath}/Build)


#RmlCore
find_library(RML_CORE_LIBRARY NAMES libRmlCore.a PATHS ${RmlUiBuildPath})
if(RML_CORE_LIBRARY)
    message(SUCCESS " RmlCore был успешно найден ${RML_CORE_LIBRARY} - RmlCore was successfully found ${RML_CORE_LIBRARY}")
else()
    message(FATAL_ERROR "Не найдена библиотека RmlCore - Cannot find RmlCore library")
endif()
#RmlDebugger
find_library(RML_DEBUGGER_LIBRARY NAMES libRmlDebugger.a PATHS ${RmlUiBuildPath})
if(RML_DEBUGGER_LIBRARY)
    message(SUCCESS " RmlDebugger был успешно найден ${RML_DEBUGGER_LIBRARY} - RmlDebugger was successfully found ${RML_DEBUGGER_LIBRARY}")
else()
    message(FATAL_ERROR "Не найдена библиотека RmlDebugger - Cannot find RmlDebugger library")
endif()
#RmlDebugger
find_library(RML_SHELL NAMES libshell.a PATHS ${RmlUiBuildPath})
if(RML_SHELL)
    message(SUCCESS " RmlShell был успешно найден ${RML_SHELL} - RmlShell was successfully found ${RML_SHELL}")
else()
    message(FATAL_ERROR "Не найдена библиотека RmlShell - Cannot find RmlShell library")
endif()
#HarfBuzz
find_library(HARFBUZZ_LIBRARY NAMES libharfbuzz.a PATHS ${HarfBazzDir})
if(HARFBUZZ_LIBRARY)
    message(SUCCESS " HarfBuzz был успешно найден ${HARFBUZZ_LIBRARY} - HarfBuzz was successfully found ${HARFBUZZ_LIBRARY}")
else()
    message(FATAL_ERROR "Не найдена библиотека HarfBuzz - Cannot find HarfBuzz library")
endif()
# Freetype
find_package(Freetype REQUIRED)
if(FREETYPE_FOUND)
    message(SUCCESS " Freetype был успешно найден ${FREETYPE_LIBRARIES} - Freetype was successfully found ${FREETYPE_LIBRARIES}")
else()
    message(FATAL_ERROR "Не найдена библиотека Freetype - Cannot find Freetype library")
endif()
#ZLIB
set(ZLIB_USE_STATIC_LIBS ON)
find_package(ZLIB REQUIRED)
if(ZLIB_FOUND)
    message(SUCCESS " Zlib был успешно найден ${ZLIB_LIBRARIES} - Zlib was successfully found ${ZLIB_LIBRARIES}")
else()
    message(FATAL_ERROR "Не найдена библиотека Zlib - Cannot find Zlib library")
endif()


add_library(rmlbackend STATIC Backends/RmlUi_Backend_SDL_SDLrenderer.cpp)

file(GLOB RML_BACKEND_SOURCES Backends/*.cpp)





message(${RML_DEBUGGER_LIBRARY})
message(${RML_CORE_LIBRARY})
target_link_libraries(rmlbackend ${RML_DEBUGGER_LIBRARY})
target_link_libraries(rmlbackend ${RML_CORE_LIBRARY})
target_link_libraries(rmlbackend ${SDL2_LIBRARIES})
target_link_libraries(rmlbackend ${FREETYPE_LIBRARY_RELEASE})
target_link_libraries(rmlbackend ${HARFBUZZ_LIBRARY})
target_link_libraries(rmlbackend ${ZLIB_LIBRARIES})

target_link_libraries(rmlbackend ${LibraryDir}/SDL2_image-2.6.3/x86_64-w64-mingw32/bin/SDL2_image.dll)

target_include_directories(rmlbackend PUBLIC ${SDL2_INCLUDE_DIR})
target_include_directories(rmlbackend PUBLIC ${LibraryDir}/SDL2_image-2.6.3/x86_64-w64-mingw32/include/SDL2)

target_include_directories(rmlbackend PUBLIC ${RmlUiIncludePath})
target_include_directories(rmlbackend PUBLIC ${RmlUiBackendsPath})

target_sources(rmlbackend PUBLIC
    ${RML_BACKEND_SOURCES}
)



add_library(frontend STATIC src/FrontEndMain.cpp)
file(GLOB FRONTEND_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB FRONTEND_SOURCES_CONTROLLERS ${CMAKE_CURRENT_SOURCE_DIR}/controllers/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/controllers/*.c)
file(GLOB FRONTEND_SOURCES_CONTROLLERS_WINDOWS ${CMAKE_CURRENT_SOURCE_DIR}/controllers/windows/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/controllers/windows/*.c)
file(GLOB FRONTEND_SOURCES_CONTROLLERS_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/controllers/forms/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/controllers/forms/*.c)
message(
    ${FRONTEND_SOURCES_CONTROLLERS}
)
message(
    ${FRONTEND_SOURCES_CONTROLLERS_WINDOWS}

)
message(    ${FRONTEND_SOURCES_CONTROLLERS_FORMS})
message(${FRONTEND_SOURCES})

target_link_libraries(frontend ${FREETYPE_LIBRARY_RELEASE})
target_include_directories(frontend PUBLIC ${FREETYPE_INCLUDE_DIRS})

target_include_directories(frontend PUBLIC ${SDL2_INCLUDE_DIR})
target_include_directories(frontend PUBLIC ${RmlUiIncludePath})
target_include_directories(frontend PUBLIC ${RmlUiBackendsPath})
target_include_directories(frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/controllers)

target_link_libraries(frontend ${RML_DEBUGGER_LIBRARY})
target_link_libraries(frontend ${RML_CORE_LIBRARY})
target_link_libraries(frontend ${SDL2_LIBRARIES})

target_link_libraries(frontend ${FREETYPE_LIBRARY_RELEASE})
target_link_libraries(frontend ${HARFBUZZ_LIBRARY})
target_link_libraries(frontend ${ZLIB_LIBRARIES})
target_link_libraries(frontend rmlbackend)


target_include_directories(frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/modules)
target_link_libraries(frontend LibGraphics)

target_sources(frontend PUBLIC
    ${FRONTEND_SOURCES}
    ${FRONTEND_SOURCES_CONTROLLERS}
    ${FRONTEND_SOURCES_CONTROLLERS_WINDOWS}
    ${FRONTEND_SOURCES_CONTROLLERS_FORMS}
)
target_compile_definitions(frontend PUBLIC RMLUI_STATIC_LIB)
target_include_directories(frontend PUBLIC
    inc
    src/interface
    ../modules/inc
)