#include "ui_texteditorwidget.h"
#include "TextEditorWidget.h"

#include <QString>
#include <QScrollBar>
#include <QFontMetrics>
#include <QDebug>
#include <QFontDatabase>

TextEditorWidget::TextEditorWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextEditorWidget())
    , highlightedIndex(-1)
{
    ui->setupUi(this);

    int fontId = QFontDatabase::addApplicationFont(":/thirdparty/Hack/bin/ttf/Hack-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont hackRegularFont(family);
    font = hackRegularFont;

    connect(ui->textEdit, &QTextEdit::textChanged, this, &TextEditorWidget::textChanged);
    connect(ui->textEdit->verticalScrollBar(), &QScrollBar::sliderMoved, this, &TextEditorWidget::textScrolled);
    connect(ui->textEdit->verticalScrollBar(), &QScrollBar::valueChanged, this, &TextEditorWidget::textScrolled);
    textChanged();

    ui->textEdit->document()->setPlainText(ui->textEdit->document()->toPlainText());
    ui->textEdit->verticalScrollBar()->setValue(0);
    ui->textEdit_2->verticalScrollBar()->setValue(0);
}

TextEditorWidget::~TextEditorWidget()
{
}

void TextEditorWidget::textChanged()
{
    QString lineNumberText = "";
    for(int i=0; i<ui->textEdit->document()->lineCount(); ++i)
        lineNumberText += QString::number(i) + '\n';
    ui->textEdit_2->document()->setPlainText(lineNumberText);
    //TODO: character length
    ui->textEdit_2->setMaximumWidth(15*QString::number(ui->textEdit->document()->lineCount()-1).length());
    ui->textEdit_2->setMinimumWidth(15*QString::number(ui->textEdit->document()->lineCount()-1).length());
    ui->textEdit->setFont(font);
    ui->textEdit_2->setFont(font);
    textScrolled(); 
}

void TextEditorWidget::textScrolled(int position)
{
    ui->textEdit_2->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->value());
}
