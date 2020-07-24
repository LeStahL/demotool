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

#include "ColorProvider.hpp"

#include <QRandomGenerator>
#include <QDebug>

ColorProvider::ColorProvider()
{
    syntaxColors = provideSyntaxColors();
}

ColorProvider::~ColorProvider()
{
}

QList<QColor> ColorProvider::provide()
{
    QColor color = QColor::fromRgb(1.00*255.,0.81*255.,0.57*255.);

    // Set hue to a random value to achieve different colors each call
    color.setHsv(QRandomGenerator::global()->generateDouble()*255., color.hsvSaturation(), color.value());

    QList<QColor> colors;
    for(int i=0; i<10; ++i)
    {
        float mixAmount = (float)i/9.;
        color.setHsv(color.hsvHue(), color.hsvSaturation(), mixAmount*255.);
        colors.push_back(color);
    }

    return colors;
}

QList<QColor> ColorProvider::provideSyntaxColors()
{
    QColor color = QColor::fromRgb(1.00*255.,0.81*255.,0.57*255.);

    QList<QColor> colors;
    for(int i=0; i<10; ++i)
    {
        float mixAmount = (float)i/9.;
        color.setHsv(mixAmount*255., color.hsvSaturation(), color.value());
        colors.push_back(color);
    }

    return colors;
}