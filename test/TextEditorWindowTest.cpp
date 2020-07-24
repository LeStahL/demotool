#include "TextEditorWindow.hpp"
#include <QApplication>

int main(int argc, char **args)
{
    QApplication application(argc, args);
    TextEditorWindow textEditorWindow;
    textEditorWindow.show();
    return application.exec();
}