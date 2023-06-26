//
// Created by shiby on 23-6-19.
//

#ifndef CPPDATASTRUCTURE_FORWARD_LIST_H
#define CPPDATASTRUCTURE_FORWARD_LIST_H

#include <cstdlib>

template<typename T>
struct Node {
    struct Node *next;
    T data;

    explicit Node(T data_, struct Node<T> *node_ = nullptr) : data(data_), next(node_) {};
};


// singly linked list based forward_list.
// head -> ... -> rear
template<typename T>
class ForwardList {

    typedef Node<T> node_type;
    typedef T value_type;

private:
    node_type *head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() { clear(); }

    class Iterator {
    public:
        node_type *ptr;

        explicit Iterator(node_type *pointer) : ptr(pointer) {};

        Iterator &operator++() {
            ptr = ptr->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return ptr != other.ptr;
        }

        T &operator*() const {
            return ptr->data;
        }
    };

    using iterator = Iterator;
    using const_iterator = const Iterator;

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }


    value_type front() {
        if (empty()) exit(-1);
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        node_type *nextNode;
        while (!empty()) {
            nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }

    void push_front(value_type data) {
        auto *nNode = new Node<value_type>(data, head);
        head = nNode;
    }

    void pop_front() {
        if (empty()) exit(-1);
        node_type *nextNode = head->next;
        delete head;
        head = nextNode;
    }

    iterator insert_after(const_iterator pos, const T &value) {
        auto nNode = new node_type(value, pos.ptr->next);
        pos.ptr->next = nNode;
        return pos;
    }

    iterator erase_after(const_iterator pos) {
        node_type *nextNode = pos.ptr->next;
        pos.ptr->next = pos.ptr->next->next;
        delete nextNode;
        return iterator(pos.ptr->next);
    }
};

#endif //CPPDATASTRUCTURE_FORWARD_LIST_H
