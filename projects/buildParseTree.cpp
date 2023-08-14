//
// Created by sparkai on 23-8-14.
//

#include "binaryTree.h"
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>



// 全括号表达式到表达式树的转换


void buildParseTree(const std::string &parseString, BinaryTree &tree) {
    std::stack<BinaryTree *> tStack;
    tStack.push(&tree);

    std::istringstream iss(parseString);
    char tmp;
    while (!iss.eof()) {
        iss >> tmp;

        if (tmp == '(') {
            auto nextNode = tStack.top()->insertLeft(' ');
            tStack.push(nextNode);
        } else if (tmp == '+' or tmp == '-' or tmp == '*' or tmp == '/') {
            tStack.top()->setRootValue(tmp);
            auto nextNode = tStack.top()->insertRight(' ');
            tStack.push(nextNode);
        } else if (tmp >= 48 and tmp <= 57) {
            tStack.top()->setRootValue(tmp);
            tStack.pop();
        } else if (tmp == ')') {
            tStack.pop();
        }
    }

    std::cout << "end" << std::endl;
}

int opers(char a, char b, char op) {
    int x = int(a) - 48;
    int y = int(b) - 48;

    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            throw std::runtime_error("Unsupport operate");
    }

}

int evaluate(BinaryTree *pTree) {
    auto leftChild = pTree->getLeftChild();
    auto rightChild = pTree->getRightChild();
    if (leftChild != nullptr and rightChild != nullptr) {
        return opers(evaluate(leftChild), evaluate(rightChild), pTree->getRootValue());
    } else {
        return pTree->getRootValue();
    }
}


int main() {
    std::string text = "(3+(5*2))";
    BinaryTree tree;
    buildParseTree(text, tree);
    int result = evaluate(&tree);
    std::cout << result << std::endl;


    return 0;
}
