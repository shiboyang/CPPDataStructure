//
// Created by shiby on 22-11-9.
//


#include "vector.h"

int main() {

    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1.push_back(3);
    v1[3] = 200;
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();


    for (auto x: v1) {
        std::cout << x << std::endl;
    }

    Vector<double> v2;
    v2.push_back(1.5l);
    v2.push_back(1.5l);
    v2.push_back(1.5l);
    v2.push_back(1.5l);


    for (auto x: v2) {
        std::cout << x << std::endl;
    }


    Vector<std::string> v3;
    v3.push_back("123");
    v3.push_back("abc");
    v3.push_back("456");

    std::cout << v3[1] << std::endl;


    return 0;
}