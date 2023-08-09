//
// Created by shiby on 23-8-9.
//
#include<string>
#include <iostream>
/*
 * 问题拆解是通过分步骤拆解的：
 * 如果我需要将#1上的3个盘移动到#3上，需要分3步来执行
 * 1. 将#1上的n-1个盘移动到#2上
 * 2. 将#1上的第n个盘移动到#3上
 * 3. 将#2上的n-1个盘移动到#3上
 *
 * 好难理解
 */

void moveDisk(int disk, const std::string &fromPole, const std::string &toPole);

void moveTower(int height, const std::string &fromPole, const std::string &withPole, const std::string &toPole) {
    if (height >= 1) {
        moveTower(height - 1, fromPole, toPole, withPole);
        moveDisk(height, fromPole, toPole);
        moveTower(height - 1, withPole, fromPole, toPole);
    }
}

void moveDisk(int disk, const std::string &fromPole, const std::string &toPole) {
    std::cout << "The disk[" << disk << "] from #" << fromPole << " to #" << toPole << std::endl;
}

int main() {
    moveTower(2, "1", "2", "3");
}