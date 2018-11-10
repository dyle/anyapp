/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#include <QPushButton>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

using namespace anyapp;


MainWindow::MainWindow() : QMainWindow{} {

    ui = std::make_shared<Ui_MainWindow>();
    ui->setupUi(this);

    a = new Anyapp(this);

    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->btnMakeAFoo, &QPushButton::clicked, this, &MainWindow::makeAFoo);
    connect(ui->btnQuit, &QPushButton::clicked, this, &MainWindow::close);
    connect(a, &Anyapp::fooChanged, this, &MainWindow::fooChanged);
}


void MainWindow::fooChanged() {
    ui->textEdit->append("Foo changed!");
    ui->textEdit->append(QString("Current foo: %1.").arg(a->getFoo()));
}


void MainWindow::makeAFoo() {
    a->setFoo(a->getFoo() + 1);
}

