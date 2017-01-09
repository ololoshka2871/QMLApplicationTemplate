#include "appController.hpp"
#include "meta.hpp"

namespace app {

    Controller* Controller::instance = nullptr;

    Controller::Controller() {
        if (instance) {
            throw std::runtime_error("instance already existing");
        }
    }

    Controller* Controller::Create() {
        instance = new Controller();
        return instance;
    }

    QString Controller::getVersion() {
        return Meta::versionString;
    }

    bool Controller::isDebugBuild() {
#ifdef NDEBUG
        return false;
#else
        return true;
#endif
    }
}
