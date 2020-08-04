#include "QuadraticSplineModel.hpp"

QuadraticSplineModel::QuadraticSplineModel(QuadraticSpline *_spline, QObject *parent)
    : QAbstractListModel(parent)
    , spline(_spline)
    , ownSpline(_spline == nullptr)
{
    if(ownSpline) 
        spline = new QuadraticSpline();
}

QuadraticSplineModel::~QuadraticSplineModel()
{
    if(ownSpline) delete spline;
}

int QuadraticSplineModel::rowCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant QuadraticSplineModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) 
    {
        if(index.row() == 0) return QVariant(spline->p0.x());
        else if(index.row() == 1) return QVariant(spline->p0.y());
        else if(index.row() == 2) return QVariant(spline->p1.x());
        else if(index.row() == 3) return QVariant(spline->p1.y());
        else if(index.row() == 4) return QVariant(spline->p2.x());
        else if(index.row() == 5) return QVariant(spline->p2.y());
    }
    return QVariant();
}

QVariant QuadraticSplineModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(section == 0) return QVariant(QString("p0.x"));
        else if(section == 1) return QVariant(QString("p0.y"));
        else if(section == 2) return QVariant(QString("p1.x"));
        else if(section == 3) return QVariant(QString("p1.y"));
        else if(section == 4) return QVariant(QString("p2.x"));
        else if(section == 5) return QVariant(QString("p2.y"));
    }
    return QVariant();
}

Qt::ItemFlags QuadraticSplineModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

bool QuadraticSplineModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        if(index.row() == 0) spline->p0 = QPointF(value.toDouble(), spline->p0.y());
        else if(index.row() == 1) spline->p0 = QPointF(spline->p0.x(), value.toDouble());
        else if(index.row() == 2) spline->p1 = QPointF(value.toDouble(), spline->p1.y());
        else if(index.row() == 3) spline->p1 = QPointF(spline->p1.x(), value.toDouble());
        else if(index.row() == 4) spline->p2 = QPointF(value.toDouble(), spline->p2.y());
        else if(index.row() == 5) spline->p2 = QPointF(spline->p2.x(), value.toDouble());
        return true;
    }
    return false;
}
