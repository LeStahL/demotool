#pragma once

#include "Node.hpp"

#include <QPointF>

class Line : public Node
{
    public:
    Line(QPointF p0 = QPointF(0,0), QPointF p1 = QPointF(0,0));
    ~Line() = default;

    QString toGLSL(QString variableName = QString("d")) override;

    QPointF p0, p1;
};

