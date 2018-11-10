/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */

#include <gtest/gtest.h>

#include <anyapp/anyapp.hpp>

using namespace anyapp;


TEST(AnyappTest, TestFooValue) {
    
    Anyapp a(nullptr);

    a.setFoo(42);
    EXPECT_EQ(a.getFoo(), 42);
}

