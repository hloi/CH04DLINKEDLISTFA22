/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newCxxTest.h
 * Author: hloi
 *
 * Created on January 26, 2018, 3:52 PM
 */

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
#include "list.h"

using KW::list;

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testMyFunction() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions. 
        list<int> a_list;
        a_list.push_front(2);
        a_list.push_back(5);
        a_list.push_back(8);

        TS_ASSERT_EQUALS(*a_list.begin(), 2);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 5);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 8);
        a_list.pop_front();
        // should test size equals to zero
    }

    // how to test list_const_iterator
    void testConstList() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        list<int> a_list;
        a_list.push_front(2);
        a_list.push_back(5);
        a_list.push_back(8);
        const list<int> a_list2 = a_list;  // make a shallow copy of const list (did not call the assignment operator)

        // test list_const_iterator
        // const_iterator begin should be called
        TS_ASSERT_EQUALS(*a_list2.begin(), 2);  // const list does not allow to remove element
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 2);  // const list does not allow to remove element
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 2);  // const list does not allow to remove element
        a_list.pop_front();

    }
    // how to test assignment operator
    void testAssignmentOperator() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        list<int> a_list;
        a_list.push_front(2);
        a_list.push_back(5);
        a_list.push_back(8);
        list<int> a_list2;
        a_list2 = a_list;  // call assignment operator

        TS_ASSERT_EQUALS(*a_list.begin(), 2);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 5);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 8);
        a_list.pop_front();
        // should test size equals to zero

        TS_ASSERT_EQUALS(*a_list2.begin(), 2);
        a_list2.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 5);
        a_list2.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 8);
        a_list2.pop_front();
        // should test size equals to zero
    }

    // how to test copy constructor
    void testCopyConstructor() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        list<int> a_list;
        a_list.push_front(2);
        a_list.push_back(5);
        a_list.push_back(8);
        list<int> a_list2(a_list);
        TS_ASSERT_EQUALS(*a_list.begin(), 2);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 5);
        a_list.pop_front();
        TS_ASSERT_EQUALS(*a_list.begin(), 8);
        a_list.pop_front();
        // should test size equals to zero

        TS_ASSERT_EQUALS(*a_list2.begin(), 2);
        a_list2.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 5);
        a_list2.pop_front();
        TS_ASSERT_EQUALS(*a_list2.begin(), 8);
        a_list2.pop_front();
        // should test size equals to zero

    }

};
#endif /* NEWCXXTEST_H */

