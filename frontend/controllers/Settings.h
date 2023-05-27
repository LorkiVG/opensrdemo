#include "controllers/Controller.h"

class SettingsController : public BaseController {
public:
    void Initialize(const fs::path name);
};


class SettingsControllerFactory : public BaseControllerFactory {
public:
    std::unique_ptr<BaseController> Create() override;
};