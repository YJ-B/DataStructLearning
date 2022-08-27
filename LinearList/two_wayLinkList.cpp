//
// Created by 鲍伟 on 2022/8/23.
// 双向链表
//
#include <cstdlib>

typedef int E;

struct two_wayListNode {
    E element;
    struct two_wayListNode * next;
    struct two_wayListNode * prev;
};

typedef struct two_wayListNode* two_wayNode;

void initTwoWayNode(two_wayNode head) {
    head->next = head->prev = nullptr;
}

bool insertTwoWayNode(two_wayNode head, E element, int index) {
    if (index < 1) return false;
    while(--index) {
        head = head->next;
        if(head == nullptr) return false;
    }
    auto node = (two_wayNode) malloc(sizeof(struct two_wayListNode));
    if (node == nullptr) return false;
    node->element = element;
    if (head->next != nullptr) {
        node->next = head->next;
        head->next->prev = node;
    } else {
        node->next = nullptr;
    }

    head->next = node;
    node->prev = head;
    return true;
}

bool deleteTwoWayNode(two_wayNode head, int index) {
    if (index < 1)  return false;
    while (--index) {
        head = head -> next;
        if (head == nullptr) return false;
    }
    if (head->next == nullptr) return false;
    auto tmp = head->next;
    if (head->next->next) {
        head->next->next->prev = head;
        head->next = head->next->next;
    } else {
        head->next = nullptr;
    }
    free(tmp);
    return true;
}

void printTwoWayLinkList(two_wayNode head) {
    while(head->next) {
        head = head->next;
        printf("%d ", head->element);
    }
    printf("\n");
    do {
        printf("%d ", head->element);
        head = head->prev;
    } while(head->prev);
}