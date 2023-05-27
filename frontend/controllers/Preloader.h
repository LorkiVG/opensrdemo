#include "controllers/Controller.h"

class PreloaderController : public BaseController {
    public:
        void Initialize(const fs::path name);
};


class PreloaderControllerFactory : public BaseControllerFactory {
    public:
        std::unique_ptr<BaseController> Create() override;
};
