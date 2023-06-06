//
// Created by shiby on 22-11-9.
//
#include <iostream>
#include "queue.h"

void test_queue() {
    Queue<int> queue(20);


    for (int i = 0; i < 20; ++i) {
        queue.push(i + 100);
    }

    std::cout << "The front element of queue is " << queue.front() << std::endl;
    std::cout << "The back element of queue is " << queue.back() << std::endl;

    queue.pop();
    queue.pop();
    queue.pop();
    std::cout << "After pop 3 times" << std::endl;

    std::cout << "The front element of queue is " << queue.front() << std::endl;
    std::cout << "The back element of queue is " << queue.back() << std::endl;
    std::cout << "The size of queue is " << queue.size() << std::endl;

    queue.push(100);
    queue.push(101);
    std::cout << "push 100 and 101" << std::endl;
    std::cout << "The front element of queue is " << queue.front() << std::endl;
    std::cout << "The back element of queue is " << queue.back() << std::endl;
    std::cout << "The size of queue is " << queue.size() << std::endl;

    std::cout << "begin pop element: " << std::endl;
    while (!queue.empty()) {
        std::cout << queue.front() << std::endl;
        queue.pop();
    }
}

int main() {
    test_queue();

    return 0;
}