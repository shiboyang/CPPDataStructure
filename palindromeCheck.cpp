//
// Created by shiby on 23-6-9.
//
#include "struct/deque.h"
#include <iostream>


bool palindrome_check(const std::string &s) {
    bool ret = true;
    DeQueue<char> dq;

    for (char it: s) {
        std::cout << it << std::endl;
        dq.push_back(it);
    }

    for (int i = 0; i < dq.size() / 2; ++i) {
        const char ch1 = dq.front();
        const char ch2 = dq.back();
        if (ch1 == ch2) {
            dq.pop_back();
            dq.pop_front();
            continue;
        } else {
            ret = false;
        }
    }
    return ret;
};

int main() {
    std::string s = "abc";
    bool is_pal = palindrome_check(s);
    std::cout << "the string '" << s << "' palindrome check result is " << is_pal << std::endl;
    s = "radar";
    is_pal = palindrome_check(s);
    std::cout << "the string '" << s << "' palindrome check result is " << is_pal << std::endl;

    return 0;
}