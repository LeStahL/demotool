#include "ui_texteditorwindow.h"
#include "TextEditorWindow.hpp"

#include <QString>

TextEditorWindow::TextEditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditorWindow())
{
    ui->setupUi(this);
    renderGraphMatrix = new Matrix("Render Graph");
    renderGraphModel = new MatrixModel(renderGraphMatrix);
    ui->tableView_2->setModel(renderGraphModel);
    ui->tableView_2->update();
}

TextEditorWindow::~TextEditorWindow()
{

}