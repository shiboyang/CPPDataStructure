//
// Created by shiby on 23-6-26.
//

#ifndef CPPDATASTRUCTURE_LIST_H
#define CPPDATASTRUCTURE_LIST_H


#include <stdexcept>

template<typename T>
class List {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;

    class iterator;

    class const_interator;

private:
    struct node_type {
        value_type data;
        node_type *previous;
        node_type *next;

        node_type(value_type data_, node_type *previous_, node_type *next_ = nullptr) : data(data_),
                                                                                        previous(previous_),
                                                                                        next(next_) {};
    };

    node_type *head = nullptr;
    node_type *rear = nullptr;
    int count = 0;

public:
    List() = default;

    ~List();

    reference front();

    const_reference front() const;

    reference back();

    const_reference back() const;

    bool empty();

    int size();

    void clear();

    iterator insert(const_interator pos, value_type value);

    void push_back(const_reference value);

    void pop_back();

    void push_front(const_reference value);

    void pop_front();

    iterator begin();

    iterator end();


};

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
typename List<T>::reference List<T>::front() {
    if (empty()) throw std::runtime_error("Empty List");
    return head->data;
}

template<typename T>
typename List<T>::const_reference List<T>::front() const {
    if (empty()) throw std::runtime_error("Empty List");
    return rear->data;
}

template<typename T>
bool List<T>::empty() {
    return head == nullptr;
}

template<typename T>
int List<T>::size() {
    return count;
}

template<typename T>
void List<T>::clear() {
    while (!empty()) {
        node_type *nextNode = head->next;
        head->next = nextNode->next;
        free(nextNode);
        count = 0;
    }
};

template<typename T>
void List<T>::push_back(const_reference value) {
    auto current = rear;
    auto newNode = new List<T>::node_type(value, current);
    if (empty()) {
        head = rear = newNode;
    } else {
        current->next = newNode;
        rear = newNode;
    }
    ++count;
};

template<typename T>
void List<T>::pop_back() {
    if (!empty()) {
        auto previousNode = rear->previous;
        free(rear);
        rear = previousNode;
        rear->next = nullptr;
    }
    --count;
};

template<typename T>
void List<T>::push_front(const_reference value) {
    auto newNode = new List<T>::node_type(value, nullptr, head);
    if (empty()) {
        head = rear = newNode;
    } else {
        head = newNode;
    }
    ++count;
};

template<typename T>
void List<T>::pop_front() {
    if (!empty()) {
        auto nextNode = head->next;
        free(head);
        head = nextNode;
        head->previous = nullptr;
    }
    --count;
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return List::iterator(head);
};

template<typename T>
typename List<T>::iterator List<T>::end() {
    return List::iterator(nullptr);
};

template<typename T>
typename List<T>::reference List<T>::back() {
    if (empty()) throw std::runtime_error("Empty List");
    return rear->data;
}


template<typename T>
typename List<T>::const_reference List<T>::back() const {
    if (empty()) throw std::runtime_error("Empty List");
    return rear->data;
}


template<typename T>
class List<T>::iterator {
private:
    node_type *ptr;
public:
    explicit iterator(node_type *ptr_) : ptr(ptr_) {};

    iterator &operator++() {
        ptr = ptr->next;
        return *this;
    }

    bool operator!=(iterator &other) {
        return ptr != other.ptr;
    }

    reference operator*() const {
        return ptr->data;
    }

};

#endif //CPPDATASTRUCTURE_LIST_H
