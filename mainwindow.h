#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#include <QMainWindow>
#include <QAction>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected slots:
    void addEntry();
    void removeEntry();

private:
    //QAction *addButton;
    //QAction *removeButton;
    QWidget* createList();



};

#endif // MAINWINDOW_H
