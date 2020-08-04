#pragma once

#include <QObject>
#include <QAbstractItemView>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>

#include "QuadraticSpline.hpp"
#include "QuadraticSplineModel.hpp"

class QuadraticSplineView : public QAbstractItemView
{
    Q_OBJECT

    public:
    QuadraticSplineView(QGraphicsScene *scene, QWidget *parent = nullptr);
    ~QuadraticSplineView() = default;

    private slots:
    void update(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());

    private:
    QGraphicsRectItem item1,
        item2,
        item3;
    double handleSize = 5.;
    QGraphicsItemGroup itemGroup;
    QGraphicsScene *scene;
};