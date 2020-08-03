#include "QuadraticSpline.hpp"

QuadraticSpline::QuadraticSpline(QPointF _p0, QPointF _p1, QPointF _p2)
    : p0(_p0)
    , p1(_p1)
    , p2(_p2)
{
}

QString QuadraticSpline::toGLSL(QString variableName)
{
    return (QString("float d;")
        + "dspline2(uv, vec2(%1,%2), vec2(%3,%4), vec2(%5,%6), d);")
        .arg(p0.x()).arg(p0.y())
        .arg(p1.x()).arg(p1.y())
        .arg(p2.x()).arg(p2.y());
}