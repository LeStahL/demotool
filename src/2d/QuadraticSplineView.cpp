#include "QuadraticSplineView.hpp"

QuadraticSplineView::QuadraticSplineView(QGraphicsScene *_scene, QWidget *parent)
    : QAbstractItemView(parent)
    , scene(_scene)
{
    QuadraticSplineModel *quadraticSplineModel = (QuadraticSplineModel *)model();
    if(quadraticSplineModel != nullptr)
    {
        itemGroup.addToGroup(&item1);
        itemGroup.addToGroup(&item2);
        itemGroup.addToGroup(&item3);

        for(int i=0; i<6; ++i) update(quadraticSplineModel->index(i,0), quadraticSplineModel->index(i,0));
    }
    this->connect(quadraticSplineModel, &QuadraticSplineModel::dataChanged, this, &QuadraticSplineView::update);
}

void QuadraticSplineView::update(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    if(topLeft.row() != bottomRight.row()) return;
    QModelIndex index = topLeft;

    QuadraticSplineModel *quadraticSplineModel = (QuadraticSplineModel *)model();
    
    if(index.row() == 0 || index.row() == 1)
    {
        QPointF p0 = QPointF(quadraticSplineModel->data(quadraticSplineModel->index(0,0)).toDouble(),
            quadraticSplineModel->data(quadraticSplineModel->index(1,0)).toDouble());
        item1.setRect(p0.x() - .5*handleSize, p0.y() - .5*handleSize,
            handleSize, handleSize);
    }
    else if(index.row() == 2 || index.row() == 3)
    {
        QPointF p1 = QPointF(quadraticSplineModel->data(quadraticSplineModel->index(2,0)).toDouble(),
            quadraticSplineModel->data(quadraticSplineModel->index(3,0)).toDouble());
        item2.setRect(p1.x() - .5*handleSize, p1.y() - .5*handleSize,
            handleSize, handleSize);
    }
    else if(index.row() == 4 || index.row() == 5)
    {
        QPointF p2 = QPointF(quadraticSplineModel->data(quadraticSplineModel->index(4,0)).toDouble(),
            quadraticSplineModel->data(quadraticSplineModel->index(5,0)).toDouble());
        item2.setRect(p2.x() - .5*handleSize, p2.y() - .5*handleSize,
            handleSize, handleSize);
    }
    scene->update();
}