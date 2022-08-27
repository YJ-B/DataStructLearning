//
// Created by 鲍伟 on 2022/8/23.
//
#include <cstdlib>

typedef int E;

struct ListNode {
    E element;
    struct ListNode* next;
};

typedef struct ListNode * Node;

void initLinkList(Node node) {
    node->next = nullptr;
}

bool insertLinkList(Node head, E element, int index) {
    if (index < 1) return false;
    // 找到插入位置
    while(--index) {
        head = head->next;
        if (head == nullptr) return false;
    }
    // 创建节点
    Node node = (Node)malloc(sizeof(struct ListNode));
    if (node == nullptr) return false;
    node->element = element;
    // 插入操作
    node->next = head->next;
    head->next = node;
    return true;
}

bool deleteLinkList(Node head, int index) {
    if(index < 1) return false;
    while(--index) {
        head = head->next;
        if(head == nullptr) return false;
    }
    if(head->next == nullptr) return false;
    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return true;
}

E * getLinkList(Node head, int index) {
    if (index < 1) return nullptr;
    do {
        head = head->next;
        if (head == nullptr) return nullptr;
    } while (--index);
    return &head->element;
}

int findLinkList(Node head, E element) {
    head = head->next;  // 先走到第一个节点
    int i = 1;  // 计数器
    while (head) {
        if (head -> element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeLinkList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

void printLinkList(Node head) {
    while(head->next) {
        head = head->next;  // 头节点中不存储元素
        printf("%d ", head->element);
    }
}