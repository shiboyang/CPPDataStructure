//
// Created by shiby on 22-11-15.
//

#ifndef CPPDATASTRUCTURE_VECTOR_H
#define CPPDATASTRUCTURE_VECTOR_H

#include <array>
#include <iostream>


template<typename T>
struct Data {
    Data() = default;

    explicit Data(T value) : _value(value) {};

    Data &operator=(const T &v) {
        _value = v;
        return *this;
    }


    friend std::ostream &operator<<(std::ostream &os, Data<T> d) {
        os << d._value;
        return os;
    }

private:
    T _value;
};


template<typename T>
class Vector {
public:
    typedef T value_type;
    typedef Data<value_type> *pointer;

    Vector() = default;

    ~Vector() {
        delete[] data;
    }

    void push_back(value_type v) {
        if (data == nullptr) {
            data = new Data<value_type>[1];
            *data = v;
        } else {
            auto tmp_d = new Data<T>[length + 1];
            std::copy(data, data + length, tmp_d);
            tmp_d[length] = v;
            delete data;
            data = tmp_d;
        }
        length++;
    };

    void pop_back() {};


    Data<value_type> operator[](int i) {
        return data[i];
    }


private:
    int length = 0;
    pointer data = nullptr;

};


#endif //CPPDATASTRUCTURE_VECTOR_H
