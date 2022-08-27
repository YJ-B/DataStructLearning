//
// Created by 鲍伟 on 2022/8/23.
// 循环链表
//
#include<cstdlib>

typedef int E;

struct CirListNode {
    E element;
    CirListNode* next;
};

typedef CirListNode* CirNode;

void initCirLinkList(CirNode head) {
    head->next = head;
}