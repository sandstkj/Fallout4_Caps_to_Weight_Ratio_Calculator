/**********************************************************************
Copyright (C) 2015  Kyle Sandstrom

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item(QString tempName, double tempValue, double tempWeight);

    QString getName();
    double getValue();
    double getWeight();
    double getVPW(); //Get value per weight

    Item* getNext();
    void setNext(Item* successor);
    void setValue(double tempValue);
    void setWeight(double tempWeight);

private:
    QString name;
    double value;
    double weight;
    char type;
    char rarity;
    Item* next;

};

#endif // ITEM_H
