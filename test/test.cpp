//
// Created by shiby on 23-6-26.
//
#include <list>
#include <iostream>


int main() {

    std::list<float> list;
    auto x = list.front();
    std::cout << x << std::endl;
    std::cout << list.back() << std::endl;

    return 0;
}