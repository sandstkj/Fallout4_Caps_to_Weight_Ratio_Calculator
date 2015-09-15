
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

#include "item.h"

Item::Item(QString tempName, double tempValue, double tempWeight)
{
    name = tempName;
    value = tempValue;
    weight = tempWeight;
    next = this;
}

QString
Item::getName(){
    return name;
}

double
Item::getValue(){
    return value;
}

double
Item::getWeight(){
    return weight;
}

double
Item::getVPW(){
    return value/weight;
}

Item*
Item::getNext(){
    return next;
}

void
Item::setNext(Item* successor){
    next = successor;
}

void
Item::setValue(double tempValue){
    value = tempValue;
}

void
Item::setWeight(double tempWeight){
    weight = tempWeight;
}
