//
// Created by sparkai on 23-8-16.
//

#include "binary_search_tree.h"
#include <vector>

void test_get(int key, BinarySearchTree &bst) {
    auto res = bst.get(key);
    if (res.first) {
        std::cout << "Find key " << key << " and the payload is " << res.second << std::endl;
    } else {
        std::cout << "Not find key " << key << std::endl;
    }
}

void test_binary_search_tree() {
    std::vector<int> vec{14, 31, 93, 94, 70, 23, 73};
    BinarySearchTree bst;
    for (auto x: vec) {
        bst.insert(x, x);
    }

    bst.inorder();

    test_get(31, bst);
    test_get(32, bst);
}


int main() {
    test_binary_search_tree();

    return 0;
}