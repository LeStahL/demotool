#pragma once

#include <QWidget>
#include <QWheelEvent>
#include <QFont>

namespace Ui { class TextEditorWidget; }

class TextEditorWidget : public QWidget
{
    Q_OBJECT

    public:
    explicit TextEditorWidget(QWidget *parent = nullptr);
    ~TextEditorWidget();

    private slots:
    void textChanged();
    void textScrolled(int position = 0);

    private:
    Ui::TextEditorWidget *ui;
    int highlightedIndex;
    QFont font;
};