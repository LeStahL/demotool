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

#pragma once

#include <QTableView>
#include <QObject>
#include <QKeyEvent>
#include <QPushButton>
#include <QLabel>
#include <QSize>
#include <QModelIndex>
#include <QModelIndexList>

#include "MatrixHeaderView.hpp"

class MatrixView : public QTableView
{
    Q_OBJECT
    
public:
    MatrixView(QWidget *parent = 0);
    virtual ~MatrixView();
    void update();
    QSize horizontalHeaderSectionSize();
    
private slots:
    void addColumnSlot();
    void addRowSlot();
    void removeColumnSlot(int index);
    void removeRowSlot(int index);
    
    void keyPressEvent(QKeyEvent *e);

private:
    int m_column_width;
    MatrixHeaderView *m_vertical_header_view, *m_horizontal_header_view;
    QModelIndexList m_copy_buffer;
};
