//
// Created by shiby on 23-8-11.
//
#include <vector>
#include <iostream>
#include <iterator>

void gapInsertionSort(std::vector<int> &vec, int start, int gap);


/**
 * 希尔排序
 * 复杂度：O(n)~O(n^1.5)
 * 希尔排序是将数据切分为多个子列表，再对子列表进行插入排序，直到最后对整个列表进行一次插入排序
 * 希尔排序相比直接对整个数据列表做插入排序大大降低了数据移动的次数
 * @param vec
 */
void shellSort(std::vector<int> &vec) {

    int subListCount = vec.size() / 2;

    while (subListCount > 0) {
        for (int i = 0; i < subListCount; ++i) {
            gapInsertionSort(vec, i, subListCount);
        }
        subListCount = subListCount / 2;
    }
}

void gapInsertionSort(std::vector<int> &vec, int start, int gap) {
    for (int i = start + gap; i < vec.size(); i += gap) {
        int value = vec[i];
        int index = i;
        while (index >= gap and vec[index - gap] > value) {
            vec[index] = vec[index - gap];
            index -= gap;
        }
        vec[index] = value;
    }
}

int main() {
    std::vector<int> vec{1, 4, 5, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};

    shellSort(vec);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}