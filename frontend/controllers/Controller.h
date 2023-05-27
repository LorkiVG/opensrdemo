#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <boost/regex.hpp>
#include "modules/inc/FilePaths.h"


// Базовый наследуемый класс для всех контроллеров
class BaseController {
    public:
        virtual ~BaseController();
};
// Базовая наследуемая фабрика для контроллеров
class BaseControllerFactory 
{
    public:
        virtual ~BaseControllerFactory();
        virtual std::unique_ptr<BaseController> Create();
};

class BaseControllerValidator {
    public:
        virtual ~BaseControllerValidator();
};