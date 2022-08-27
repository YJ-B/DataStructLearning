//
// Created by 鲍伟 on 2022/8/23.
// 栈(链表实现)
//

#include <cstdlib>

typedef int E;

struct StackListNode {
    E element;
    struct StackListNode * next;
};

typedef StackListNode * stackNode;

void initStackLinklist(stackNode head) {
    head->next = nullptr;
}

bool PushStackLinkList(stackNode head, E element) {
    auto node = (StackListNode *)malloc(sizeof(struct StackListNode));
    if (node == nullptr) return false;
    node->element = element;
    // 头插法
    node->next = head->next;
    head->next = node;
    return true;
}


bool isEmptyStackLinkList(stackNode head) {
    return head->next == nullptr;
}


E PopStackLink(stackNode head) {

    stackNode tmp = head->next;
    E e = tmp->element;
    head->next = head->next->next;
    free(tmp);
    return e;
}


void printStackLinkList(stackNode head) {
    head = head->next;
    while(head) {
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}