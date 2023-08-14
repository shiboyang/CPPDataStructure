//
// Created by shiby on 23-8-10.
//
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

void initVector(int size, std::vector<int> &vec, bool isOrdered = true) {
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }
    if (!isOrdered) {
        std::shuffle(vec.begin(), vec.end(), std::mt19937(std::random_device()()));
    }
}


int binarySearch(std::vector<int> &orderedVec, int item) {

    int start = 0;
    int end = orderedVec.size() - 1;
    int pos = -1;

    while (start <= end && pos < 0) {
        int midPos = (start + end) / 2;
        if (orderedVec[midPos] == item) {
            pos = midPos;
        } else {
            if (orderedVec[midPos] < item) {
                start = midPos + 1;
            } else {
                end = midPos - 1;
            }
        }
    }
    return pos;
}


int binarySearch(std::vector<int> &vec, int start, int end, int item) {

    int midPos = (start + end) / 2;
    if (vec[midPos] == item) return midPos;
    if (start > end) return -1;

    if (vec[midPos] < item)
        return binarySearch(vec, midPos + 1, end, item);
    else
        return binarySearch(vec, start, midPos - 1, item);
}


int main() {

    std::vector<int> vec;
    initVector(10, vec, true);

    //test code
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    for (auto i: vec) {
        int pos1 = binarySearch(vec, i);
        int pos2 = binarySearch(vec, 0, vec.size() - 1, i);
        if (pos1 == pos2) {
            std::cout << "Pass: ";
        } else {
            std::cout << "Fail: ";
        }
        std::cout << "The version of loop return: " << pos1 << " and the recursive return: " << pos2
                  << std::endl;

    }


}