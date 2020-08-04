#pragma once

#include "Node.hpp"

class Path : public Node
{
    public:
    Path() = default;
    virtual ~Path() = default;

    QString toGLSL(QString variableName = QString("d")) override;
};