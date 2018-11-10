/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#ifndef ANYAPP_HPP
#define ANYAPP_HPP

#include <QObject>


namespace anyapp {


/**
 * A simple object.
 */
class Anyapp : public QObject {
    
    Q_OBJECT

    int fooValue = 0;       /**< Some Value to get/set. */

public:


    /**
     * Constructor.
     *
     * @param   parent      Parent Qobject.
     */
    explicit Anyapp(QObject * parent) : QObject(parent) {}

   
    /**
     * Gets a foo.
     *
     * @return  The current value of foo.
     */
    int getFoo() const;

public slots:

    /**
     * Sets a new foo.
     *
     * @param   value       Foos new value.
     */
    void setFoo(int value);

signals:

    /**
     * We got a new foo!
     */
    void fooChanged();
};


}


#endif

