#include "ui_texteditorwindow.h"
#include "TextEditorWindow.hpp"

#include <QString>
#include <QFile>

TextEditorWindow::TextEditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditorWindow())
{
    QFile file(":/TextEditorWindow.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);

    ui->setupUi(this);
    renderGraphMatrix = new Matrix("Render Graph");
    renderGraphModel = new MatrixModel(renderGraphMatrix);
    ui->tableView_2->setModel(renderGraphModel);
    ui->tableView_2->update();
}

TextEditorWindow::~TextEditorWindow()
{

}

void TextEditorWindow::randomDarkPalette()
{

}

void TextEditorWindow::randomLightPalette()
{

}