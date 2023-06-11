//
// Created by shiby on 23-6-11.
//

#include <iostream>
#include <sstream>
// 递归算法的实现定律：
// 1. 递归算法必须有一个结束条件. 最小规模问题的返回条件
// 2. 递归算法在运行过程中一定能改变状态向基本结束条件演进. 问题规模是逐渐减小的
// 3. 递归算法必须是调用自身的. 解决减小了规模的相同问题.


std::ostringstream toStr(int n, int base) {
    static char convertString[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'};

    if (n < base) {
        std::ostringstream osstream;
        osstream << convertString[n];
        return osstream;
    } else {
        return toStr(n / base, base) << convertString[n % base];
    }
}


int main() {
    std::ostringstream osstream = toStr(100, 2);
    std::cout << osstream.str() << std::endl;

    return 0;
}