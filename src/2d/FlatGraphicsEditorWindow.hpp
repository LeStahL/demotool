#pragma once

#include <QMainWindow>

#include "QuadraticSplineView.hpp"
#include "QuadraticSplineModel.hpp"

#include <QGraphicsScene>

namespace Ui { class FlatGraphicsEditorWindow; }

class FlatGraphicsEditorWindow : public QMainWindow
{
    public:
    FlatGraphicsEditorWindow(QApplication *application, QWidget *parent = nullptr);
    virtual ~FlatGraphicsEditorWindow();

    QApplication *application;
    Ui::FlatGraphicsEditorWindow *ui;
    QGraphicsScene scene;
};
