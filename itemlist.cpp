
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

#include "itemlist.h"
#include <iostream>
#include <string>
#include <QString>

itemList::itemList()
{
    sentinel = new Item("Sentinel", 1000, 1);
    sentinel->setNext(sentinel);
    size = 1;
}

Item*
itemList::at(int index){
    Item* request = sentinel;
    for (int i = 0; i < index; i++){
        request = request->getNext();
    }
    return request;
}

void
itemList::updateList(){


}

void
itemList::addEntry(QString name, double value, double weight){
    Item* inductee = new Item(name, value, weight);
    insertEntry(inductee);
}

void
itemList::insertEntry(Item* inductee){
    Item* currentComparable = sentinel;
    Item* previousComparable = sentinel;

    for (int i = 0; i < size; i++){
        if (inductee->getVPW() >= currentComparable->getVPW() || sentinel->getVPW() == sentinel->getNext()->getVPW()){
            previousComparable->setNext(inductee);
            inductee->setNext(currentComparable);
            size++;
            return;
        }
        previousComparable = currentComparable;
        currentComparable = currentComparable->getNext();
    }

}

void
itemList::removeEntry(QString tempName){
    if (QString::compare(tempName, sentinel->getName(), Qt::CaseInsensitive) == 0){
        std::cout << "May not remove " << tempName.toStdString() << std::endl;
        return;
    }
    Item* currentComparable = sentinel;
    Item* previousComparable = sentinel;

    for (int i = 0; i < size; i++){
        if (QString::compare(tempName, currentComparable->getName(), Qt::CaseInsensitive) == 0){
            previousComparable->setNext(currentComparable->getNext());
            delete currentComparable;
            size--;
            return;
        }
        previousComparable = currentComparable;
        currentComparable = currentComparable->getNext();
    }
    std::cout << tempName.toStdString() << " does not exist" << std::endl;
    return;
}

void
itemList::listEntries(){
    for (int i = 0; i < size; i++){
        std::cout << at(i)->getName().toStdString() << "     " << QString::number(at(i)->getVPW()).toStdString() << std::endl;
    }
}

int
itemList::getSize(){
    return size;
}
