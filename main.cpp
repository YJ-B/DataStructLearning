#include <iostream>

// 线性表类
#include "LinearList/SeqList.cpp"
#include "LinearList/LinkList.cpp"
#include "LinearList/two_wayLinkList.cpp"
#include "LinearList/CirLinkList.cpp"
// 栈
#include "LinearList/Stack/StackSeqList.cpp"
#include "LinearList/Stack/StackLinkList.cpp"
// 队列
#include "LinearList/Queue/QueueSeqList.cpp"
#include "LinearList/Queue/QueueLinkList.cpp"

// ---------------------------------------------------
// 树
#include "Tree/BiTreeLinkList.cpp"
#include "Tree/ClueBiTreeLinkList.cpp"
#include "Tree/BiSearchTree.cpp"
#include "Tree/AVL.cpp"
#include "Tree/HuffmanTree.cpp"
// 堆
#include "Tree/heap.cpp"

// ---------------------------------------------------
// 搜索
#include "Search/BruteSearch.cpp"
#include "Search/BinarySearch.cpp"
#include "Search/HashMap.cpp"

// ---------------------------------------------------
// 排序



int main() {
//    ========================= 线性表 LinearList ===========================
//    -------------------------- 顺序存储 SeqList ----------------------------
//    struct List list{};
//    if (initSeqList(&list)){
//        for (int i = 0; i < 30; ++i) {
//            insertSeqList(&list, i*10, i+1);
//        }
//        printSeqList(&list);
//        printf("%d\n", list.capacity);
//        deleteSeqList(&list, 5);
//        printSeqList(&list);
//        printf("%d", *getSeqList(&list, 3));
//    }
//    else {
//        printf("顺序表初始化失败！");
//    }

//    -------------------------- 链式存储 LinkList ----------------------------
//    ------------------------------- 单链表 ----------------------------------
//    struct ListNode head{};
//    initLinkList(&head);
//    for (int i = 1; i <= 3; ++i) {
//        insertLinkList(&head, i*100, 1);
//    }
//    printLinkList(&head);
//    printf("\n");
//    deleteLinkList(&head, 1);
//    printLinkList(&head);
//    printf("\n%d", *getLinkList(&head, 1));
//    printf("\n%d", findLinkList(&head, 400));
//    printf("\n%d", sizeLinkList(&head));

//    ------------------------- 双向链表 -----------------------------
//    struct two_wayListNode head{};
//    initTwoWayNode(&head);
//    for (int i = 1; i<= 5; i++) {
//        insertTwoWayNode(&head, i*50, i);
//    }
//    deleteTwoWayNode(&head, 1);
//    printTwoWayLinkList(&head);

//    ------------------- 栈 Stack (Sequence List) --------------------
//    struct Stack stack{};
//    initStack(&stack);
//    for (int i = 0; i < 10; ++i) {
//        PushStack(&stack, i*100);
//    }
//    PrintStack(&stack);
//    while (!isStackEmpty(&stack)) {
//        printf("%d ", PopStack(&stack));
//    }

//    --------------------- 栈 Stack (Link List) ----------------------
//    struct StackListNode SLNode{};
//    initStackLinklist(&SLNode);
//    for (int i = 0; i < 3; ++i) {
//        PushStackLinkList(&SLNode, i*10);
//    }
//    printStackLinkList(&SLNode);
//    while(!isEmptyStackLinkList(&SLNode)) {
//        printf("%d\n", PopStackLink(&SLNode));
//    }


//    ----------------- 队列 Queue (Sequence List) -----------------------
//    struct QueueSeqList QSLNode {};
//    initQueueSeqList(&QSLNode);
//    for (int i = 0; i < 5; ++i) {
//        offerQueueSeqList(&QSLNode, i*100);
//    }
//    PrintQueueSeqList(&QSLNode);
//    while (!isEmptyQueueSeqList(&QSLNode)) {
//        printf("%d ", pollQueueSeqList(&QSLNode));
//    }

//    -------------------- 队列 Queue (Link List) ------------------------
//    struct QueueLinkListFR QLLNode{};
//    initQueueLinkList(&QLLNode);
//    for (int i = 0; i < 5; ++i) {
//        offerQueueLinkList(&QLLNode, i*100);
//    }
//    PrintQueueLinkList(&QLLNode);
//    while(!isEmptyQueueLinkList(&QLLNode)) {
//        printf("%d ", pollQueueLinkList(&QLLNode));
//    }

//    ========================= 树 Tree ============================
//    ------------------- 二叉树 BiTree (Link List) -----------------------
//    testForBuildingBiTree();

//    -------------- 二叉线索树 ClueBiTree (Link List) -----------------------
//    testForClueBiTree();

//    -------------- 二叉查找树 BiSearchTree (Link List) ----------------------
//    testForBiSearchTree();

//    --------------------- 平衡二叉树 AVL (Link List) ------------------------
//    testForAVL();

//    --------------- 哈夫曼树 Huffman Tree (Link List) ------------------------
//    testForHuffmanTree();

//    ========================= 排序 Sort ===========================
//    // 有序数组
//    int testNumsOrders[] = {1, 3, 5, 7, 9, 11};
//    int OrdersLength = 6;
//    int OrdersFindTarget = 7;
//    int OrdersNotFindTarget = 99;
//    // 无序数组
//    int testNumsNoOrders[] = {9, 7, 12, 8, 4,7,10};
//    int NoOrdersLength = 7;
//    int NoOrdersFindTarget = 8;
//    int NoOrdersNotFindTarget = 88;

//    -------------------- 堆 Heap ------------------------
//    testForMaxHeap();

//    ========================= 查找 Search ===========================
//    -------------------- 暴力查找 BruteSearch ------------------------
//    int result;
//    result = bruteSearchOrder(testNumsOrders, OrdersLength, OrdersFindTarget);
//
//    if (result != -1) {
//        printf("Brute Search has found, the Result is: %d", testNumsOrders[result]);
//    } else {
//        printf("Brute Search has not Found!");
//    }

//    -------------------- 二分查找 BinarySearch -----------------------
//    // 对数组要求有序
//    int result;
//    result = binarySearch(testNumsOrders, 0, OrdersLength - 1, OrdersFindTarget);
//    if (result != -1) {
//        printf("Binary Search has found, the Result is: %d", testNumsOrders[result]);
//    } else {
//        printf("Binary Search has not Found!");
//    }
//    return 0;

//    -------------------- 哈希表 HashMap -----------------------
    testForHashMap();
}
