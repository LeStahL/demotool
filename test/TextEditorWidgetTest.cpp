#include "TextEditorWidget.h"
#include <QApplication>

int main(int argc, char **args)
{
    QApplication application(argc, args);
    TextEditorWidget textEditorWidget;
    textEditorWidget.show();
    return application.exec();
}