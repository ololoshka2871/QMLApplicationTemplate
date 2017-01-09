#ifndef _APPCONTROLLER_HPP_
#define _APPCONTROLLER_HPP_

#include <QObject>

namespace app {

    class Controller : public QObject {
        Q_OBJECT
        Q_PROPERTY(bool debugBuild READ isDebugBuild CONSTANT)
        Q_PROPERTY(QString version READ getVersion CONSTANT)
    private:
        Controller();
    public:
        static Controller* instance;
        static Controller* Create();
        QString getVersion();
        bool isDebugBuild();
    };
}

#endif /* _APPCONTROLLER_HPP_ */
