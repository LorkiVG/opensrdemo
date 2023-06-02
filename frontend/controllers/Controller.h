#pragma once
#include <string>
#include <memory>
#include <thread>
#include <chrono>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string/replace.hpp>
#include "ContextManager.h"
#include "EventListenerInstancer.h"
#include "EventManager.h"

//TODO Придумать как эти переменные сделать более лучшим способом без использования глобалок

/// @brief Главное окно для всех контроллеров 
extern Window* mainWindow;
/// @brief Главное менеджер форм для всех контроллеров
extern FormManager* mainFormManager;


/// @brief Базовый наследуемый абстрактный класс для всех контроллеров
class BaseController {
    public:
        /// @brief Деструктор контроллера (в основном можно оставлять базовым)
        virtual ~BaseController();   
        /// @brief Инициализация контроллера
        virtual void Initialize();
};

/// @brief Базовая наследуемая абстракная фабрика контроллеров
class BaseControllerFactory 
{
    public:
        /// @brief Деструктор фабрики
        virtual ~BaseControllerFactory();
        /// @brief Создать контроллер на фабрике
        /// @return Умный указатель на контроллер
        virtual std::unique_ptr<BaseController> Create();
};