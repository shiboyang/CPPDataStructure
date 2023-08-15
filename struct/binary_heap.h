//
// Created by sparkai on 23-8-15.
//

#ifndef CPPDATASTRUCTURE_BINARY_HEAP_H
#define CPPDATASTRUCTURE_BINARY_HEAP_H

#include <vector>
#include <iterator>
#include <iostream>

class BinaryHeap {

public:
    BinaryHeap() = default;

    void insert(int key) {
        vec.push_back(key);
        // move upward along with tree path.
        percUp(vec.size() - 1);
    };


    int findMin() {
        return vec[1];
    }

    int delMin() {
        int retVal = vec[1];
        vec[1] = vec.back();
        percDown(1);
        return retVal;
    }


    bool isEmpty() {
        return vec.size() == 1;
    };


    void buildHeap(std::vector<int> &vec2) {
        std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec));
        int index = (vec.size() - 1) / 2;
        for (; index > 0; --index) {
            this->percDown(index);
        }

    }

    void print_heap() {
        std::copy(vec.begin() + 1, vec.end(), std::ostream_iterator<int>(std::cout, " | "));
    }


private:
    std::vector<int> vec{0};


    void percUp(int index) {
        while (index / 2 != 0) {
            if (vec[index / 2] > vec[index]) {
                int tmp = vec[index / 2];
                vec[index / 2] = vec[index];
                vec[index] = tmp;
            } else
                break;
            index /= 2;
        }
    }

    void percDown(int index) {
        while (index * 2 < vec.size() - 1) {
            int nextIndex = index * 2;
            if (index * 2 + 1 <= vec.size() - 1) {
                if (vec[index * 2] < vec[index * 2 + 1]) {
                    nextIndex = index * 2;
                } else {
                    nextIndex = index * 2 + 1;
                }
            }
            if (vec[index] > vec[nextIndex]) {
                int tmp = vec[nextIndex];
                vec[nextIndex] = vec[index];
                vec[index] = tmp;
            } else
                break;

            index = nextIndex;
        }
    }


};


#endif //CPPDATASTRUCTURE_BINARY_HEAP_H
