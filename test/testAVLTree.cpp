//
// Created by sparkai on 23-8-17.
//
#include "alv_tree.h"
#include "visualizer.h"

void test_avl_tree() {
    AVLTree avlTree;


    for (int i = 0; i < 15; ++i) {
        avlTree.put(i, i);
    }
    visualizer vis(avlTree);
    vis.visualize();

    avlTree.inorder();
}

int main() {
    test_avl_tree();

    return 0;
}
