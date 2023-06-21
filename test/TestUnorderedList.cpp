//
// Created by liuquan on 23-6-21.
//
#include "unorderedlist.h"
#include <iostream>

int main() {

    List<int> list;
    std::cout << "List is empty: " << list.empty() << std::endl;
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    std::cout << "List back: " << list.back() << std::endl;
    std::cout << "List front: " << list.front() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;


}