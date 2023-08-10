//
// Created by shiby on 23-8-10.
//
#include <vector>
#include <iterator>
#include <iostream>

/**
 * 插入排序
 * 将一个列表切分为两个部分，前半部分为已排好序的部分，后半部分为未排序部分，
 * 每次将从已排序位置向后取一个值，向前比较，如果小于前面的值，则将前面的值的位置往后移动一位，
 * 直到遇到比小于currentValue的值，那么当前的index指向的位置就是currentValue应该在的位置。
 * List [1,2,3,| 33, 12, 45, -1]
 *
 * 复杂度：O(n^2)
 * 如果列表已排好序的情况下，总比对次数为O(n)
 * 由于插入排序仅包含一次赋值操作，所以相对于未优化版本的bubbleSort性能要好一点。
 * @param vec
 */
void insertSort(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int value = vec[i];
        int index = i;
        while (index > 0 and vec[index - 1] > value) {
            vec[index] = vec[index - 1];
            index--;
        }
        vec[index] = value;
    }
}

int main() {

    //-346 -12 -1 1 4 5 6 7 45 58 78 112 344 2342
    std::vector<int> vec{1, 4, 5, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};

    insertSort(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}