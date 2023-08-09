//
// Created by shiby on 23-6-26.
//
#include <list>
#include <iostream>

int func(int a, int b) {
    return a + b;
}

int main() {


    func(10, 20);
    const int x = 100;
    const int y = 200;
    func(x, y);

    int a[0];
    a[0] = 100;

    std::cout << a[0] << std::endl;

    return 0;
}