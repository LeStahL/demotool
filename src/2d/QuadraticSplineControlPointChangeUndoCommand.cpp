#include "QuadraticSplineControlPointChangeUndoCommand.hpp"

QuadraticSplineControlPointChangeUndoCommand::QuadraticSplineControlPointChangeUndoCommand(QPointF p0new, QPointF p1new, QPointF p2new, QuadraticSplineModel *_model)
    : QUndoCommand()
    , model(_model)
    , oldP0(QPointF(model->data(model->createIndex(0, 0)).toDouble(), 
        model->data(model->createIndex(1,0)).toDouble()))
    , oldP1(QPointF(model->data(model->createIndex(2, 0)).toDouble(), 
        model->data(model->createIndex(3,0)).toDouble()))
    , oldP2(QPointF(model->data(model->createIndex(4, 0)).toDouble(), 
        model->data(model->createIndex(5,0)).toDouble()))
    , newP0(p0new)
    , newP1(p1new)
    , newP2(p2new)
{
    setText(QString("Quadratic Spline Control Point Changed."));
}

void QuadraticSplineControlPointChangeUndoCommand::redo()
{
    model->setData(model->createIndex(0,0), QVariant(newP0.x()));
    model->setData(model->createIndex(1,0), QVariant(newP0.y()));
    model->setData(model->createIndex(2,0), QVariant(newP1.x()));
    model->setData(model->createIndex(3,0), QVariant(newP1.y()));
    model->setData(model->createIndex(4,0), QVariant(newP2.x()));
    model->setData(model->createIndex(5,0), QVariant(newP2.y()));
}

void QuadraticSplineControlPointChangeUndoCommand::undo()
{
    model->setData(model->createIndex(0,0), QVariant(oldP0.x()));
    model->setData(model->createIndex(1,0), QVariant(oldP0.y()));
    model->setData(model->createIndex(2,0), QVariant(oldP1.x()));
    model->setData(model->createIndex(3,0), QVariant(oldP1.y()));
    model->setData(model->createIndex(4,0), QVariant(oldP2.x()));
    model->setData(model->createIndex(5,0), QVariant(oldP2.y()));
}