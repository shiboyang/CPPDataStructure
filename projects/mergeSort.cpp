//
// Created by shiby on 23-8-12.
//

#include <vector>
#include <iostream>
#include <iterator>

/**
 * 归并排序
 * 这个是有点难到我了，但思想很简单。
 * 算法实现分3步：
 * 1. 分割：以列表的中间位置分割列表，直到分割成只包含1个元素的列表
 * 2. 合并：分别从两个子列表取值，将取出小的的元素放置进主列表中，直到其中一个子列表被取空
 * 3. 合并剩余项：将剩下的子列表直接拼接到上面的主列表中(因为子列表是已经排序好的，所以可以直接合并)。
 * > 为什么每次合并要放进主列表中：
 *  因为这个算法是递归调用，算法在递归退出时按顺序退出，在每层递归退出时，当前的两个子列表应该是排好序的子列表，所以我们要在算法内部更新
 *  传入的这个子列表。
 * @param vec
 * @param start
 * @param end
 */
void mergeSort(std::vector<int> &vec, int start, int end) {
    if (end - start == 1) return;
    int midPos = (start + end) / 2;

    mergeSort(vec, start, midPos);
    mergeSort(vec, midPos, end);

    int i = start;
    int j = midPos;
    std::vector<int> vec1;
    while (i < midPos and j < end) {
        if (vec[i] < vec[j]) {
            vec1.push_back(vec[i]);
            ++i;
        } else {
            vec1.push_back(vec[j]);
            ++j;
        }
    }

    while (i < midPos) {
        vec1.push_back(vec[i]);
        ++i;
    }

    while (j < end) {
        vec1.push_back(vec[j]);
        ++j;
    }

    for (int l = start; l < end; ++l) {
        vec[l] = vec1[l - start];
    }
}


int main() {
    std::vector<int> vec{1, 4, 5, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};
//    std::vector<int> vec{2, 1};
    mergeSort(vec, 0, 14);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}

