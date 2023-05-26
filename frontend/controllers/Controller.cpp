#include <Controller.h>
BaseController::~BaseController() = default;
BaseControllerFactory::~BaseControllerFactory() = default;
std::unique_ptr<BaseController> BaseControllerFactory::Create()
{
    return std::make_unique<BaseController>();
};

namespace BaseControllerValidator 
{
    bool MainValidator(const std::string& input);
};