#ifndef _APP_INSTANCE_HPP_
#define _APP_INSTANCE_HPP_

class QString;
class QQuickView;

namespace app {

    class Instance {
    private:
        QQuickView* m_view = nullptr;
    private:
        static Instance* instance;
        Instance();
        void init();
        void AddFontDir(const QString&);
    public:
        static int Execute(int, char**);
    };
}

#endif /* _APP_INSTANCE_HPP_ */
