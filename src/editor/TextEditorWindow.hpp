#pragma once

#include <QMainWindow>
#include <QList>
#include <QColor>

#include "Matrix.hpp"
#include "MatrixModel.hpp"
#include "ColorProvider.hpp"

namespace Ui { class TextEditorWindow; }

class TextEditorWindow : public QMainWindow
{
    Q_OBJECT

    public:
    explicit TextEditorWindow(QWidget *parent = nullptr);
    virtual ~TextEditorWindow();

    private slots:
    void randomDarkPalette();
    void randomLightPalette();

    private:
    void updateStyleSheet();
    Ui::TextEditorWindow *ui;
    Matrix *renderGraphMatrix;
    MatrixModel *renderGraphModel;
    QList<QColor> palette;
    bool darkMode;
    QString unstyledStyleSheet;
    ColorProvider colorProvider;
};