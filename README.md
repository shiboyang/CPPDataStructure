# 数据结构与算法

## Data Structure

### Stack

栈结构是一种连续的内存，stack pointer 从高地址位开始，每入栈一个数据sp向低位移动数据内存长度的字节，如果栈容量按照一个数据内存长度作为单位，那么入栈一个数据，栈容量减一。当count为0时栈满，sp位于栈内存最低位。

栈的设计结构中，内存地址连续，栈指针从最高地址开始，所以进栈相当于站指针下移，出栈相当于栈指针上移，新入栈的数据总是位于站指针的上方(假设高内存地址在上，0内存地址在下)，因此出栈过程中，我们只需要将指针向高位移动（上移），因此最先入栈的数据也最先出栈。

### Queue

* forward_list：单向链表，只能从队尾入队，从队首出队。

![image-20230818115303131](/home/sparkai/CLionProjects/CPPDataStructure/images/image-20230818115303131.png)

* 序列实现
  * 如果是使用Array实现单向链表，这样的单向链表支持random access，还支持O(1)下标访问，在任一节点可以随意前后移动，缺点是在列表初始化的时候就固定了大小，扩容操作复杂度高需要O(n)数据拷贝，所以我认为这种实现方式已经不算是一个单向链表，缺失了链表的基本特性--随意扩容，这种实现方式最多算是对Array的数据读写、删除的一种限制。
  * append
    * 在容量范围内O(1)
    * 扩容需要O(n)的data copy
  * insert
    * 中间插入需要该节点以后O(n)得数据拷贝
  * delete
    * 中间删除需要该节点以后O(n)个数据前移拷贝
  * search
    * random access 速度 O(1)
* 链式实现
  * 链式实现方式，是native的实现方式。保留了链表原本的特性，可以无限的在链表尾部增加节点，同样继承了链表的一些缺陷，查找数据需要从Head端开始逐个遍历，为了提升append的速度，一般在实现过程中会用Tail保存最后一个节点，用于直接添加新的节点。
  * 

* deque：双向链表

* list

### Heap

* Binary Heap

### Hash

### Tree

* Binary Tree
* Binary Search Tree
* AVL Tree


## Algorithm

### Search

* Linear search

* Binary Search

### Sort

* bubble sort
* select sort
* insert sort
* shell sort
* merge sort
* quick sort