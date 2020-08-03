#pragma once

#include <QAbstractListModel>
#include <QUndoStack>

#include "QuadraticSpline.hpp"

class QuadraticSplineModel : public QAbstractListModel
{
    public:
    explicit QuadraticSplineModel(QuadraticSpline *spline, QObject *parent = nullptr);
    ~QuadraticSplineModel();

    // Show
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(const QModelIndex &index, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Edit
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole) override;

    private:
    QuadraticSpline *spline;
    bool ownSpline;
};
