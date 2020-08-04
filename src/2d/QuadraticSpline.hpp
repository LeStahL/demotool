#pragma once

#include "Node.hpp"

#include <QPointF>

class QuadraticSpline : public Node
{
    public:
    QuadraticSpline(QPointF p0 = QPointF(0.,0.), QPointF p1 = QPointF(0.,0.), QPointF p2 = QPointF(0.,0.));
    ~QuadraticSpline() = default;

    QString toGLSL(QString variableName = QString("d")) override;

    QPointF p0, p1, p2;
};
