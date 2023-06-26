//
// Created by shiby on 23-6-27.
//
#include <iostream>
#include "list.h"

int main() {

    List<int> list;
    // 4 2 1 3 5
    list.push_back(1);
    list.push_front(2);
    list.push_back(3);
    list.push_front(4);
    list.push_back(5);


    for (auto l: list) {
        std::cout << l << std::endl;
    }
    std::cout << "pop front" << std::endl;
    list.pop_front();


    for (auto l: list) {
        std::cout << l << std::endl;
    }

    std::cout << "pop back" << std::endl;
    list.pop_back();
    for (auto l: list) {
        std::cout << l << std::endl;
    }
    std::cout << "the first element is " << list.front() << std::endl;
    std::cout << "the last element is " << list.back() << std::endl;

    return 0;
}
