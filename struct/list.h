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

    class const_iterator; /* const_iterator != const iterator */


private:
    struct node_type {
        value_type data;
        node_type *previous;
        node_type *next;

        node_type(const value_type data_,
                  node_type *previous_,
                  node_type *next_ = nullptr) : data(data_),
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

//    iterator insert(const_iterator &pos, value_type value);

    iterator insert(iterator &pos, value_type value);

    void push_back(const_reference value);

    void pop_back();

    void push_front(const_reference value);

    void pop_front();

    iterator begin();

    const_iterator begin() const;

    const_iterator cbegin() const;

    iterator end();

    const_iterator end() const;

    const_iterator cend() const;


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
        delete head;
        head = nextNode;
    }
    count = 0;
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
        if (head == rear) {
            delete head;
            head = rear = nullptr;
        } else {
            auto latest = rear;
            rear = rear->previous;
            delete latest;
            rear->next = nullptr;
        }
    }
    --count;
};

template<typename T>
void List<T>::push_front(const_reference value) {
    auto newNode = new List<T>::node_type(value, nullptr, head);
    if (empty()) {
        head = rear = newNode;
    } else {
        head->previous = newNode;
        head = newNode;
    }
    ++count;
};

template<typename T>
void List<T>::pop_front() {
    if (!empty()) {
        if (head == rear) {
            delete head;
            head = rear = nullptr;
        } else {
            auto first = head;
            head = head->next;
            delete first;
            head->previous = nullptr;
        }
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

    explicit iterator(node_type *ptr_) : ptr(ptr_) {};
public:
    iterator &operator++() {
        ptr = ptr->next;
        return *this;
    }

    bool operator!=(const iterator &other) {
        return ptr != other.ptr;
    }

    bool operator==(const iterator &other) {
        return ptr == other.ptr;
    }

    reference operator*() const {
        return ptr->data;
    }

    friend List<T>;
};

template<typename T>
class List<T>::const_iterator {
private:
    // const_iterator the const qualified field is ptr.
    node_type const *ptr;

    explicit const_iterator(node_type const *ptr_) : ptr(ptr_) {};
public:

    const_iterator operator++() {
        ptr = ptr->next;
        return *this;
    };

    bool operator!=(const const_iterator &other) {
        return ptr != other.ptr;
    }

    bool operator==(const const_iterator &other) {
        return ptr == other.ptr;
    }

    const_reference operator*() {
        return ptr->data;
    }

    friend List<T>;
};

//template<typename T>
//auto List<T>::insert(List::const_iterator &pos, value_type value) -> iterator {
//    auto currentNode = pos.ptr;
//    if (currentNode == nullptr) {
//        // Iterator(end)
//        push_back(value);
//        return iterator(rear);
//    } else if (pos == cbegin()) {
//        push_front(value);
//        return iterator(head);
//    } else {
//        auto newNode = new node_type(value, currentNode->previous, currentNode);
//        newNode->previous->next = newNode;
//        newNode->next->previous = newNode;
//        ++count;
//        return iterator(newNode);
//    }
//}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const {
    return const_iterator(head);
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const {
    return const_iterator(nullptr);
}

template<typename T>
typename List<T>::const_iterator List<T>::cbegin() const {
    return const_iterator(head);
}

template<typename T>
typename List<T>::const_iterator List<T>::cend() const {
    return const_iterator(nullptr);
}

template<typename T>
typename List<T>::iterator List<T>::insert(List::iterator &pos, value_type value) {
    auto currentNode = pos.ptr;
    if (currentNode == nullptr) {
        // Iterator(end)
        push_back(value);
        return iterator(head);
    } else if (pos == begin()) {
        push_front(value);
        return iterator(rear);
    } else {
        auto newNode = new node_type(value, currentNode->previous, currentNode);
        newNode->previous->next = newNode;
        newNode->next->previous = newNode;
        ++count;
        return iterator(newNode);
    }
}


#endif //CPPDATASTRUCTURE_LIST_H
