#pragma once

#include "QuadraticSplineModel.hpp"

#include <QUndoCommand>
#include <QModelIndex>
#include <QVariant>
#include <QPointF>

class QuadraticSplineControlPointChangeUndoCommand : public QUndoCommand
{
    public:
    QuadraticSplineControlPointChangeUndoCommand(QPointF p0new, QPointF p1new, QPointF p2new, QuadraticSplineModel *model);
    virtual ~QuadraticSplineControlPointChangeUndoCommand() = default;

    void redo() override;
    void undo() override;

    private:
    QuadraticSplineModel *model;
    QPointF oldP0,
        newP0,
        oldP1,
        newP1,
        oldP2,
        newP2;
};
