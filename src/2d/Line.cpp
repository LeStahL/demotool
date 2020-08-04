#include "Line.hpp"

Line::Line(QPointF _p0, QPointF _p1)
    : p0(_p0)
    , p1(_p1)
{
}

QString Line::toGLSL(QString variableName)
{
    return (QString("dlinesegment(uv, vec2(%1,%2), vec2(%3,%4),%5);"))
        .arg(p0.x()).arg(p0.y())
        .arg(p1.x()).arg(p1.y())
        .arg(variableName);
}
