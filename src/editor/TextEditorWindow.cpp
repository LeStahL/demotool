#include "ui_texteditorwindow.h"
#include "TextEditorWindow.hpp"

#include "ColorProvider.hpp"

#include <QString>
#include <QFile>
#include <QDebug>

TextEditorWindow::TextEditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditorWindow())
    , darkMode(true)
    , colorProvider(ColorProvider())
{
    QFile file(":/TextEditorWindow.qss");
    file.open(QFile::ReadOnly);
    unstyledStyleSheet = QLatin1String(file.readAll());
    randomDarkPalette();
    
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
    palette = colorProvider.provide();
    updateStyleSheet();
}

void TextEditorWindow::randomLightPalette()
{
    palette = colorProvider.provide();
    std::reverse(palette.begin(), palette.end());
    updateStyleSheet();
}

void TextEditorWindow::updateStyleSheet()
{
    QString styleSheet = unstyledStyleSheet;
    for(int i=0; i<10; ++i) styleSheet = styleSheet.arg(palette[i].name());
    setStyleSheet(styleSheet);
    update();
}