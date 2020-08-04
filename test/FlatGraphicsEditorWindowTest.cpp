#include <QApplication>

#include "FlatGraphicsEditorWindow.hpp"

int main(int argc, char **args)
{
    QApplication application(argc, args);

    FlatGraphicsEditorWindow window(&application);
    window.show();

    return application.exec();
}
