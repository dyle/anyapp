/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef ANYAPP_MAINWINDOW_HPP
#define ANYAPP_MAINWINDOW_HPP

#include <memory>

#include <QMainWindow>

#include <anyapp/anyapp.hpp>


class Ui_MainWindow;


namespace anyapp {


class MainWindow : public QMainWindow {

    Q_OBJECT

    std::shared_ptr<Ui_MainWindow> ui;

    anyapp::Anyapp * a = nullptr;

public:

    /**
     * Constructir.
     */
    MainWindow();

private slots:

    /**
     * A new foo emerged.
     */
    void fooChanged();


    /**
     * Makes a new foo.
     */
    void makeAFoo();

};


}


#endif
