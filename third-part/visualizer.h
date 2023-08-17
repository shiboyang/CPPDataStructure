#pragma once

#include "binary_search_tree.h"
#include <string>
#include <queue>

using namespace std;

class visualizer {

    BinarySearchTree tree_;
    Node *tree_root_;
    int tree_height_;
    int tree_nodes_;
    string **values_;

    int node_length_;
    int node_type_;
    int node_shift_factor_;
    string empty_node_;

    int space_length_;
    int space_shift_factor_;

    queue<Node *>

    breadth_first_search();

    int get_tree_height(Node *) const;

    int get_nodes_count(int) const;

    int get_subtree_width(int) const;

public:

    explicit visualizer(BinarySearchTree&, int = -1, int = -1);

    ~visualizer() = default;

    void visualize() const;

};