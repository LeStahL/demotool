/* SAEGE - ShAdEr Graph Editor v1.57 "BINGE" 
 * Copyright (C) 2019  Alexander Kraus <nr4@z10.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "MatrixView.hpp"
#include "MatrixModel.hpp"
#include "ColorProvider.hpp"

#include <QDebug>
#include <QPalette>
#include <QHeaderView>
#include <QModelIndexList>
#include <QLabel>
#include <QSize>
#include <QFileDialog>
#include <QFile>

MatrixView::MatrixView(QWidget *parent)
    : QTableView(parent)
    , m_column_width(40)
{
    setEditTriggers(QAbstractItemView::DoubleClicked);
    
    m_vertical_header_view = new MatrixHeaderView(Qt::Vertical, this);
    setVerticalHeader(m_vertical_header_view);
}

MatrixView::~MatrixView()
{
    delete m_vertical_header_view;
}

void MatrixView::addRowSlot()
{
    model()->insertRows(model()->rowCount(QModelIndex()), 1);
    update();
}

void MatrixView::addColumnSlot()
{
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    model()->insertColumns(model()->columnCount(QModelIndex()), 1);
    update();
}

void MatrixView::update()
{
    QTableView::update();
}

void MatrixView::keyPressEvent(QKeyEvent* e)
{
    bool call_base = true;
    
    if(e->matches(QKeySequence::Undo))
        ((MatrixModel*)model())->undo();
    if(e->matches(QKeySequence::Redo))
        ((MatrixModel*)model())->redo();
//     if(e->matches(QKeySequence::Copy))
//     {
//         QModelIndexList selected = selectionModel()->selectedIndexes();
//         for(int i=0; i<
//     }
//     if(e->matches(QKeySequence::Paste))
//     {
//         QModelIndexList selectedIndexes = selectionModel()->selectedIndexes();
//         QModelIndex topleft = model()->index(0,0);
//         ((MatrixModel*)model())->paste(m_copy_buffer);
//     }
    if(e->matches(QKeySequence::Open))
    {
        QString fileName = QFileDialog::getOpenFileName(this,
            "Open File", "", "All files (*.*)");
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QString s;
        QTextStream s1((FILE*)&file, QIODevice::ReadOnly);
        s.append(s1.readAll());
        file.close();
//         ((MatrixModel*)model())->beginRemoveRows();
//         ((MatrixModel*)model())->beginInsertRows();
//         ((MatrixModel*)model())->beginRemoveColumns();
//         ((MatrixModel*)model())->beginInsertColumns();
        ((MatrixModel*)model())->matrix()->fromString(s);
//         ((MatrixModel*)model())->endRemoveRows();
//         ((MatrixModel*)model())->endInsertRows();
//         ((MatrixModel*)model())->endRemoveColumns();
//         ((MatrixModel*)model())->endInsertColumns();
        ((MatrixModel*)model())->updateAll();
        update();
    }
    else if(e->matches(QKeySequence::Save))
    {
        QString fileName = QFileDialog::getSaveFileName(this,
            "Save File", "", "All files (*.*)");
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << ((MatrixModel*)model())->matrix()->toString() << endl;
        }
       
    }
    
    if(e->key() == Qt::Key_Space )
    {
        QModelIndexList selectionmodel = selectionModel()->selectedIndexes();
        for(int i=0; i<selectionmodel.count(); ++i)
        {
            QVariant data = model()->data(selectionmodel.at(i), Qt::DisplayRole);
            model()->setData(selectionmodel.at(i), QVariant(1));
        }
    }
    else if(e->key() == Qt::Key_Delete)
    {
        QModelIndexList selectionmodel = selectionModel()->selectedIndexes();
        for(int i=0; i<selectionmodel.count(); ++i)
        {
            QVariant data = model()->data(selectionmodel.at(i), Qt::DisplayRole);
            model()->setData(selectionmodel.at(i), QVariant(0));
        }
    }
#define NUMERIC_KEY(_key, _num)\
    else if(e->key() == _key)\
    {\
        call_base = false;\
        QModelIndexList selectionmodel = selectionModel()->selectedIndexes();\
        for(int i=0; i<selectionmodel.count(); ++i)\
        {\
            QVariant data = model()->data(selectionmodel.at(i), Qt::DisplayRole);\
            model()->setData(selectionmodel.at(i), QVariant(_num));\
        }\
    }
    NUMERIC_KEY(Qt::Key_0, 0)
    NUMERIC_KEY(Qt::Key_1, 1)
    NUMERIC_KEY(Qt::Key_2, 2)
    NUMERIC_KEY(Qt::Key_3, 3)
    NUMERIC_KEY(Qt::Key_4, 4)
    NUMERIC_KEY(Qt::Key_5, 5)
    NUMERIC_KEY(Qt::Key_6, 6)
    NUMERIC_KEY(Qt::Key_7, 7)
    NUMERIC_KEY(Qt::Key_8, 8)
    NUMERIC_KEY(Qt::Key_9, 9)
    
    if(call_base) QTableView::keyPressEvent(e);
    update();
}

void MatrixView::removeColumnSlot(int index)
{
    model()->removeColumns(index, 1);
    update();
}

void MatrixView::removeRowSlot(int index)
{
    model()->removeRows(index, 1);
    update();
}

QSize MatrixView::horizontalHeaderSectionSize()
{
    return m_horizontal_header_view->size();
}