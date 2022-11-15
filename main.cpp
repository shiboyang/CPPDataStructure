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

    std::cout << v1[0] << std::endl;
    std::cout << v1[1] << std::endl;
    std::cout << v1[2] << std::endl;
    std::cout << v1[3] << std::endl;
    std::cout << v1[4] << std::endl;
    std::cout << v1[5] << std::endl;
    std::cout << v1[6] << std::endl;

    int x[10] = {0};
    x[1] = 100;

    return 0;
}