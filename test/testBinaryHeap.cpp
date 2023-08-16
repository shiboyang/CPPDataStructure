//
// Created by sparkai on 23-8-15.
//
#include "binary_heap.h"
#include <vector>


void test_binary_heap() {
    std::vector<int> vec{1, 4, 5, 3, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};
    BinaryHeap binHeap;
    for (auto x: vec) {
        binHeap.insert(x);
    }
    binHeap.print_heap();
    std::cout << "\n";

    std::cout << "the minimum is " << binHeap.delMin() << std::endl;
    binHeap.print_heap();
    std::cout << "\n";


    // 下沉法直接将无序列表装换成二叉堆
    BinaryHeap binHeap2;
    binHeap2.buildHeap(vec);
    binHeap2.print_heap();
    std::cout << "\n";


    std::cout << "the minimum is " << binHeap2.delMin() << std::endl;
    binHeap2.print_heap();
    std::cout << "\n";

    // Use binary heap to sort list.
    std::vector<int> result;
    while (!binHeap.isEmpty()) {
        int tmp = binHeap.delMin();
        result.push_back(tmp);
    }
    std::cout << "the sorted list is :";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

int main() {
    test_binary_heap();
    return 0;
}
