#pragma once

#include "Node.hpp"

#include <QPointF>

class QuadraticSpline : public Node
{
    public:
    QuadraticSpline(QPointF p0, QPointF p1, QPointF p2);

    QString toGLSL(QString variableName = QString("d")) override;

    QPointF p0, p1, p2;
};
