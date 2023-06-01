#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/algorithm/string/replace.hpp>

#include "Context.h"

#include "EventListenerInstancer.h"
#include "EventManager.h"

extern Window* mainWindow;
extern FormManager* mainFormManager;

// Базовый наследуемый класс для всех контроллеров
class BaseController {
    public:
        virtual ~BaseController();   
        virtual void Initialize();
};
// Базовая наследуемая фабрика для контроллеров
class BaseControllerFactory 
{
    public:
        virtual ~BaseControllerFactory();
        virtual std::unique_ptr<BaseController> Create();
};