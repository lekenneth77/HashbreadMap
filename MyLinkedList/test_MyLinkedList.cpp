#include <iostream>
#include "MyLinkedList.hpp"

//this will be error
#include <gtest/gtest.h>


//default constructor
TEST(Constructors, test0) {
    MyLinkedList<int> ll;
}

//add elements
//if we get no memory leaks, then pop works as well
TEST(Methods, test1) {
    MyLinkedList<int> ll;
    ll.add(3);
}

//get front of list
TEST(Methods, test2) {
    MyLinkedList<int> ll;
    ll.add(3);
    ASSERT_EQ(ll.front(), 3);
}

//see if list is empty
TEST(Methods, test3) {
    MyLinkedList<int> ll;
    ASSERT_EQ(ll.empty(), true);
    ll.add(3);
    ASSERT_EQ(ll.empty(), false);
    ll.pop();
    ASSERT_EQ(ll.empty(), true);
}

//test iterator empty
TEST(Iterators, test4) {
    MyLinkedList<int> ll;
    for (int i : ll) {

    }
}

//test iterator begin
TEST(Iterators, test5) {
    MyLinkedList<int> ll;
    ll.add(3);
    MyLinkedList<int>::const_iterator ci = ll.begin();
    ASSERT_EQ(*ci, 3);
}

//test iterator equals, should be false, as they're comparing positions
TEST(Iterators, test6) {
    MyLinkedList<int> ll;
    ll.add(3);
    auto ci = ll.begin();
    
    MyLinkedList<int> ll2;
    ll2.add(3);
    auto ci2 = ll2.begin();
    ASSERT_FALSE(ci == ci2);
}

//test std equals
TEST(Iterators, test7) {
    MyLinkedList<int> ll;
    ll.add(3);
    ll.add(4);
    auto ci = ll.begin();
    
    MyLinkedList<int> ll2;
    ll2.add(3);
    ll2.add(4);
    auto ci2 = ll2.begin();
    ASSERT_TRUE(ll == ll2);

    ll2.add(5);
    ASSERT_FALSE(ll == ll2);
}