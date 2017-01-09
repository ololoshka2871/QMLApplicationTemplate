#include "appInstance.hpp"

#include "meta.hpp"
#include "appController.hpp"

#include <QFontDatabase>
#include <QApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDirIterator>
#include <QDir>
#include <QQuickView>
#include <QDebug>

namespace app {

    Instance* Instance::instance = nullptr;

    Instance::Instance() {
    }

    void Instance::init() {
        QApplication::setOrganizationName(Meta::orgName);
        QApplication::setOrganizationDomain(Meta::orgDomain);
        QApplication::setApplicationName(Meta::appName);
        QApplication::setApplicationVersion(Meta::versionString);

        const QString resourceDir = ":/";

        AddFontDir(resourceDir + "fonts");

        this->m_view = new QQuickView();
        this->m_view->setTitle(QGuiApplication::applicationName());

        auto engine = this->m_view->engine();
        auto context = engine->rootContext();

        /**
          тут нужно указывать не сам каталог с файлом qmldir,
          а каталог, в котором лежит каталог с qmldir
        */
        engine->addImportPath(resourceDir + "qml");
        context->setContextProperty("App", Controller::Create());

        this->m_view->setSource(QUrl("qrc:/qml/App/window.qml"));
        this->m_view->setResizeMode(QQuickView::SizeRootObjectToView);
        this->m_view->showMaximized();
    }

    int Instance::Execute(int argc, char** argv) {
        QApplication application(argc, argv);

        if (!instance) {
            instance = new Instance();
            instance->init();
            return application.exec();
        }

        return 1;
    }

    void Instance::AddFontDir(const QString& directory) {
        QDirIterator it(directory, {"*.ttf", "*.otf"}, QDir::Files);

        while (it.hasNext()) {
            QFontDatabase::addApplicationFont(it.next());
        }
    }
}
