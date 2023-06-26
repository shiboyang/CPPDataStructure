//
// Created by shiby on 23-6-21.
//
#include "forward_list.h"
#include <iostream>

int main() {

    ForwardList<int> list;
    std::cout << "ForwardList is empty: " << list.empty() << std::endl;
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    std::cout << "ForwardList front: " << list.front() << std::endl;
    for (auto x: list) {
        std::cout << x << std::endl;
    }

    list.pop_front();
    std::cout << "after pop front, the head is " << list.front() << std::endl;

    list.pop_front();
    std::cout << "after pop front, the head is " << list.front() << std::endl;


    list.pop_front();
    std::cout << "after pop front, the head is " << list.front() << std::endl;

    for (auto x: list) {
        std::cout << x << std::endl;
    }
    list.insert_after(list.begin(), 100);
    list.insert_after(list.begin(), 10);
    list.insert_after(list.begin(), 101);

    std::cout << "insert 3 times" << std::endl;
    for (auto x: list) {
        std::cout << x << std::endl;
    }
//    list.clear();
//    std::cout << "ForwardList is empty: " << list.empty() << std::endl;
//
//
//    for (auto x: list) {
//        std::cout << x << std::endl;
//    }

    std::cout << "erase the second element" << std::endl;
    list.erase_after(list.begin());
    for (auto x: list) {
        std::cout << x << std::endl;
    }
}