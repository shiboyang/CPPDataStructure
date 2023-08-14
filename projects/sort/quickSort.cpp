//
// Created by shiby on 23-8-12.
//

#include <vector>
#include <iostream>
#include <iterator>

void quickSortHelper(std::vector<int> &vec, int start, int end);

int partition(std::vector<int> &vec, int start, int end);

/**
 * 快速排序
 * 算法复杂度：O(nlogn) ~ O(n^2)
 * 实现：
 * 1. 选取pivot value，找到pivot value在列表中的位置，返回
 * 2. 根据返回的中值的位置，分割列表，分别对列表左部分递归快排
 * 3. 对列表右半部分做递归快排
 * 4. 算法结束条件：start >= end
 *
 * partition实现：
 * 1. 假定选取第一个值作为中间值，leftMask = start rightMask = end;
 * 2. leftMask循环往右移动，满足 >= pivotValue and leftMask <= rightMask 停止循环
 * 3. rightMask循环往左移动，满足 <=pivotValue and leftMask <= rightMask 停止循环
 * 4. 判断如果leftMask <= rightMask，交换leftMask和rightMask指向的值。如果leftMask > rightMask说明已经找到了应该放置pivotValue
 * 值的地方，或者说数据已经被排布成两部分，一部分全部都小于pivotValue，一部分全部都大于pivotValue
 * 5. 此时rightMask所指向的位置就是pivotValue应该放置的位置。放置中间值，返回rightMask。
 *
 * partition函数的功能：
 * 就是将选定的pivotValue放置在数据中正确的位置，不管其他数据是否有序，仅保证选定的值在列表的正确位置。
 * quickSortHelper函数就是利用了partition函数的这一点，将列表递归的切分成左半部分和右半部分，直到对列表中每个元素都做了一次partition，
 * 最终输出的结果就保证了整个列表的有序性。
 *
 * @param vec
 */
void quickSort(std::vector<int> &vec) {
    quickSortHelper(vec, 0, vec.size() - 1);
};

void quickSortHelper(std::vector<int> &vec, int start, int end) {
    if (start < end) {
        int splitPointPos = partition(vec, start, end);
        quickSortHelper(vec, start, splitPointPos - 1);
        quickSortHelper(vec, splitPointPos + 1, end);
    }
}

int partition(std::vector<int> &vec, int start, int end) {
    int pivotValue = vec[start];
    int leftMask = start + 1;
    int rightMask = end;

    while (true) {

        while (leftMask <= rightMask and vec[leftMask] <= pivotValue) {
            ++leftMask;
        }
        while (leftMask <= rightMask and vec[rightMask] >= pivotValue) {
            --rightMask;
        }

        if (leftMask < rightMask) {
            // exchange between tow value;
            int tmp = vec[leftMask];
            vec[leftMask] = vec[rightMask];
            vec[rightMask] = tmp;
        } else {
            break;
        }
    }
    // exchange pivot value
    vec[start] = vec[rightMask];
    vec[rightMask] = pivotValue;

    return rightMask;
}

int main() {

    std::vector<int> vec{1, 4, 5, 7, 2342, 6, 78, 344, 58, 112, -1, 45, -12, -346};
    quickSort(vec);

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}

