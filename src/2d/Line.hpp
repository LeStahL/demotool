#pragma once

#include "Node.hpp"

#include <QPointF>

class Line : public Node
{
    public:
    QuadraticSpline(QPointF p0, QPointF p1, QPointF p2);

    QPointF p0, p1;
};

