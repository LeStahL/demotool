#pragma once

#include <QMainWindow>

#include "Matrix.hpp"
#include "MatrixModel.hpp"

namespace Ui { class TextEditorWindow; }

class TextEditorWindow : public QMainWindow
{
    Q_OBJECT

    public:
    explicit TextEditorWindow(QWidget *parent = nullptr);
    virtual ~TextEditorWindow();

    private slots:

    private:
    Ui::TextEditorWindow *ui;
    Matrix *renderGraphMatrix;
    MatrixModel *renderGraphModel;
};