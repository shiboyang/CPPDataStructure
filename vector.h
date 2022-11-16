//
// Created by shiby on 22-11-15.
//

#ifndef CPPDATASTRUCTURE_VECTOR_H
#define CPPDATASTRUCTURE_VECTOR_H

#include <iostream>


//template<typename T>
//struct Data {
//    Data() = default;
//
//    explicit Data(T value) : _value(value) {};
//
//    Data &operator=(const T &v) {
//        _value = v;
//        return *this;
//    }
//
//
//    friend std::ostream &operator<<(std::ostream &os, Data<T> d) {
//        os << d._value;
//        return os;
//    }
//
//private:
//    T _value;
//};


template<typename T>
class Vector {
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef size_t size_type;

    Vector() = default;

    ~Vector() {
        delete[] data;
    }

    void push_back(value_type v) {
        if (current == capacity) {
            auto tmp = new value_type[capacity * 2];
            std::copy(data, data + capacity, tmp);
            delete[] data;
            data = tmp;
            capacity *= 2;
        }
        data[current] = v;
        ++current;
    };


    void pop_back() {
        current--;
    };

    pointer begin() {
        return data;
    }

    pointer end() {
        return data + current;
    }

    value_type &operator[](size_type i) {
        return data[i];
    }

    bool empty() { return current == 0; };

    size_type size() { return current; };

    bool operator==(Vector &v) {

    };


private:
    size_type current = 0;
    pointer data = new value_type[1];
    size_type capacity = 1;

};


#endif //CPPDATASTRUCTURE_VECTOR_H
