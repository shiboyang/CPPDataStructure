cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(struct)
include_directories(third-part)

project(CPPDataStructure VERSION 1.0)


add_executable(palcheck palindromeCheck.cpp
        struct/deque.h
        )

add_executable(NumConversion projects/recursion/num_conversion.cpp)
add_executable(hanoi projects/recursion/hanoi.cpp)
add_executable(binarySearch projects/search/binarySearch.cpp)
add_executable(bubbleSort projects/sort/bubbleSort.cpp)
add_executable(insertSort projects/sort/insertionSort.cpp)
add_executable(shellSort projects/sort/shellSort.cpp)
add_executable(mergeSort projects/sort/mergeSort.cpp)
add_executable(quickSort projects/sort/quickSort.cpp)


add_executable(parseTree projects/buildParseTree.cpp)

add_executable(testForwardList test/TestUnorderedList.cpp)
add_executable(testQueue test/TestQueue.cpp)
add_executable(test test/test.cpp)
add_executable(testList test/TestList.cpp)
add_executable(testTraversalBinaryTree test/testTraversalBinaryTree.cpp)
add_executable(testBinaryHeap test/testBinaryHeap.cpp)
add_executable(testBinarySearchTree test/testBinarySearchTree.cpp
        third-part/visualizer.cpp
        )

add_executable(testAVLTree test/testAVLTree.cpp
        third-part/visualizer.cpp
        )
