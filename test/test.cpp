//
// Created by shiby on 23-6-26.
//
#include <list>
#include <iostream>
#include <sstream>

int main() {


    std::string str = "abc1234.2xxxx";
    std::istringstream iss(str);
    std::cout << iss.good() << std::endl;

//    int x;
//    iss >> x;
//    std::string ss;
//    iss >> ss;
//    std::cout << ss << std::endl;
    char c;
    iss >> c;

    std::cout << iss.good() << " : " << c << std::endl;


    return 0;
}