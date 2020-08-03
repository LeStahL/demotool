#pragma once

#include <QColor>
#include <QList>
#include <QString>

class Node
{
    public: 
    Node() = default;
    ~Node() = default;

    virtual QString toGLSL(QString variableName = QString("d")) = 0;

    QList<Node *> children;
};
