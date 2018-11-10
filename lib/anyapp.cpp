/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <anyapp/anyapp.hpp>

using namespace anyapp;


int Anyapp::getFoo() const {
    return fooValue;
}


void Anyapp::setFoo(int value) {
    if (value != fooValue) {
        fooValue = value;
        emit fooChanged();
    }
}

