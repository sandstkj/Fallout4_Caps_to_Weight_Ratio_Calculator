#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QScrollArea>
#include <QPixmap>
#include <QPushButton>
#include <iostream>
#include <QString>
#include <QWindow>
#include <QListWidget>
#include <QTextEdit>
#include "itemlist.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(200,500);
    QWidget *window = new QWidget;


    QVBoxLayout *container = new QVBoxLayout();
    //Horizontal add/subtract layout------------------------------------
    QHBoxLayout *layer1 = new QHBoxLayout();

    QPushButton *addButton = new QPushButton(QIcon("/home/kyle/Projects/Fallout4MarketHelper/plus.png"),"");
    QString buttonStyle = "QPushButton{border:none;background-color:rgba(255, 255, 255,100);}";
    addButton->setStyleSheet(buttonStyle); // Style sheet
    addButton->setIconSize(QSize(25,25));
    addButton->setMinimumSize(25,25);
    addButton->setMaximumSize(25,25);
    connect(addButton, SIGNAL(pressed()), this, SLOT(addEntry()));
    layer1->addWidget(addButton);// The horizontal layout

    QPushButton *removeButton = new QPushButton(QIcon("/home/kyle/Projects/Fallout4MarketHelper/minus.png"),"");
    QString buttonStyle2 = "QPushButton{border:none;background-color:rgba(255, 255, 255,100);}";
    removeButton->setStyleSheet(buttonStyle2); // Style sheet
    removeButton->setIconSize(QSize(25,25));
    removeButton->setMinimumSize(25,25);
    removeButton->setMaximumSize(25,25);
    connect(removeButton, SIGNAL(pressed()), this, SLOT(removeEntry()));
    layer1->addWidget(removeButton);// The horizontal layout
    layer1->setAlignment(Qt::AlignLeft);
    layer1->addStretch();
    layer1->setSpacing(0);

    /*
    QFile file("/home/kyle/Desktop/testText.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        QString line = in.readLine();
        label3->setText(line);
    }
    file.close();
    */

    //Horizontal Layout------------------------------------
    QHBoxLayout *layer2 = new QHBoxLayout();
    QScrollArea *scroll = new QScrollArea();
    //Item List--------------------------------------------

    scroll->setWidget(createList());
    layer2->addWidget(scroll);

    container->addLayout(layer1);
    container->addLayout(layer2);
    window->setLayout(container);
    setCentralWidget(window);
}

void
MainWindow::addEntry(){
    setVisible(false);
    std::cout << "addEntry triggered" << std::endl;
    QWindow *addWindow = new QWindow();
    addWindow->setVisible(true);
    addWindow->resize(500, 312); //5/8
    addWindow->setTitle("Add Entry");

    QWidget* frame = new QWidget(this, 0);

    //First Line
    QHBoxLayout *layer1 = new QHBoxLayout();

    QLabel *label1 = new QLabel("Label1", this);

    QTextEdit *nameBox = new QTextEdit();

    layer1->addWidget(label1);
    layer1->addWidget(nameBox);

    frame->setLayout(layer1);

    //addWindow->addWidget(frame);
    //Second Line

}

void
MainWindow::removeEntry(){

    std::cout << "removeEntry triggered" << std::endl;
}

QWidget*
MainWindow::createList(){
    //Initializing actual list------------
    itemList* list = new itemList();
    list->addEntry("Hello", 8.1, 5.4);
    list->addEntry("World", 6.3, 31);
    list->addEntry("I", 5.8, 1);
    list->addEntry("Am", 2, 6);
    list->addEntry("Your", 7, 4.5);
    list->addEntry("One", 10, 1);
    list->addEntry("true", 78, 5.4);
    list->addEntry("Friend", 22.2, 67);
    list->addEntry("Mr.Tree", 100, 4);
    list->addEntry("Third", 67, 3.2);
    //list->listEntries();

    QWidget *listWidget = new QWidget();

    //Gathering entry names for QVBox---------
    QVBoxLayout *nameList = new QVBoxLayout();
    for (int i = 1; i < list->getSize(); i++){
        nameList->addWidget(new QLabel(list->at(i)->getName()));
    }

    nameList->setAlignment(Qt::AlignRight);
    //Gathering entry PVW's for QVBox---------
    QVBoxLayout *VPWList = new QVBoxLayout();
    for (int i = 1; i < list->getSize(); i++){
        VPWList->addWidget(new QLabel(QString::number(list->at(i)->getVPW())));
    }
    //Splitting names and VPW for cohesive list----
    QHBoxLayout* split = new QHBoxLayout();
    split->addLayout(nameList);
    split->addLayout(VPWList);
    listWidget->setLayout(split);
    return listWidget;
}
