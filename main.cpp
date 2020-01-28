#include <view/window.h>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window window;
    window.setMinimumSize(window.sizeHint());
    window.show();
    return app.exec();
}
