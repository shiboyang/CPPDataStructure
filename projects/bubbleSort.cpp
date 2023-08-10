//
// Created by shiby on 23-8-10.
//
#include <vector>
#include <iostream>
#include <iterator>


void bubbleSort(std::vector<int> &vec) {
    int length = vec.size();

    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            if (vec[i] > vec[j]) {
                auto tmp = vec[j];
                vec[j] = vec[i];
                vec[i] = tmp;
            }
        }
    }
}

/**改进：
 *  如果在一个内循环中（第二个for内部）发现，这次的排序比较没有发生交换，说明排序已经完成了！
 * 这样的改进能降低算法复杂度吗？
 *  不能，还是O(n^2)
 * 算法复杂度：
 *  第一项比对N-1次，第二项比对N-2次。。。
 *  比对次数总和：sum(1, N-1) ==> 1/2N^2-1/2N
 *  算法复杂度: O(n^2)
 * @param vec
 */
void shortBubbleSort(std::vector<int> &vec) {
    int length = vec.size();
    for (int i = 0; i < length; ++i) {
        bool exchange = false;
        for (int j = i; j < length; ++j) {
            // descended
            if (vec[i] < vec[j]) {
                auto tmp = vec[j];
                vec[j] = vec[i];
                vec[i] = tmp;
                exchange = true;
            }
        }
        // not happened exchange signify sort is competed.
        if (!exchange) break;
    }
}


/**
 * 改进2 Select sort
 * 减少交换次数，在第二个循环内部使用一个变量保存最大(最小)的值的位置，内循环结束后进行一次交换
 * @param vec
 */
void selectSort(std::vector<int> &vec) {
    int length = vec.size();

    for (int i = 0; i < length; ++i) {
        int maxValuePos = -1;
        for (int j = i; j < length; ++j) {
            if (vec[i] < vec[j]) maxValuePos = j;
        }
        if (maxValuePos == -1) break; // not happen exchange
        else {
            int tmp = vec[maxValuePos];
            vec[maxValuePos] = vec[i];
            vec[i] = tmp;
        }
    }
}

int main() {
    std::vector<int> vec{1, 4, 5, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};
    std::vector<int> vec2(vec.begin(), vec.end());

    bubbleSort(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    shortBubbleSort(vec);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}