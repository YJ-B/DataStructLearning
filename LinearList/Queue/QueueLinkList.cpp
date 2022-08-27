//
// Created by 鲍伟 on 2022/8/26.
// 队列 链表实现
//

#include <cstdlib>

typedef int E;
struct QueueLinkListNode {
    E element;
    QueueLinkListNode * next;
};

typedef QueueLinkListNode* QLLNode;

struct QueueLinkListFR {
    QLLNode front, rear;
};

typedef QueueLinkListFR* LinkedQueue;

bool initQueueLinkList(LinkedQueue queue) {
    auto node = (QLLNode) malloc(sizeof (struct QueueLinkListNode));
    if(node == nullptr) return true;
    queue->rear = queue->front = node;
    return true;
}


bool offerQueueLinkList(LinkedQueue queue, E element) {
    auto node = (QLLNode) malloc(sizeof (struct QueueLinkListNode));
    if (node == nullptr) return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
}


bool isEmptyQueueLinkList(LinkedQueue queue) {
    return queue->front == queue->rear;
}


E pollQueueLinkList(LinkedQueue queue) {
    QLLNode tmp = queue->front->next;
    E e = tmp->element;
    queue->front->next = queue->front->next->next;
    if (queue->rear == tmp) queue->rear = queue->front; // 如果队尾是等待出队的节点，队尾需要回到队首的位置上
    free(tmp);
    return e;
}

void PrintQueueLinkList(LinkedQueue queue) {
    QLLNode node = queue->front->next;
    while (node) {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("\n");
}