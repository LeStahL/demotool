#include "ui_flatgraphicseditorwindow.h"
#include "FlatGraphicsEditorWindow.hpp"

FlatGraphicsEditorWindow::FlatGraphicsEditorWindow(QApplication *_application, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlatGraphicsEditorWindow)
    , application(_application)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

FlatGraphicsEditorWindow::~FlatGraphicsEditorWindow()
{
    delete ui;
}
