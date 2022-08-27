//
// Created by 鲍伟 on 2022/8/26.
//

typedef int E;

typedef struct HuffmanTreeNode {
    E element;
    struct HuffmanTreeNode * left;
    struct HuffmanTreeNode * right;
    int value;  // 权值
} *HFMTNode;

typedef HFMTNode T;

typedef struct HuffmanNode {
    T element;
    struct HuffmanNode * next;
} *HMNode;

struct HuffmanQueue {
    HMNode front, rear;
};

typedef struct HuffmanQueue * LinkedHuffmanQueue;

bool initHuffmanQueue(LinkedHuffmanQueue queue) {
    auto node = (HMNode)malloc(sizeof(struct HuffmanNode));
    if (node == nullptr) return false;
    queue->front = queue->rear = node;
    node->next = nullptr;
    return true;
}

bool offerHuffmanQueue(LinkedHuffmanQueue queue, T element) {
    auto node = (HMNode)malloc(sizeof(struct HuffmanNode));
    if (node == nullptr) return false;
    node->element = element;
    node->next = nullptr;
    HMNode preHuff = queue->front;
    while (preHuff->next && preHuff->next->element->value <= element->value) {
        // 从头节点开始往后挨个看，知道找到第一个小于当前值的节点
        preHuff = preHuff->next;
    }
    if (preHuff == queue->rear) {
        // 如果找到的位置是最后一个，直接插入就行
        queue->rear->next = node;
        queue->rear = node;
    } else {
        // 否则插队
        node->next = preHuff->next;
        preHuff->next = node;
    }
    return true;
}

T pollHuffmanQueue(LinkedHuffmanQueue queue) {
    HMNode tmp = queue->front->next;
    T e = tmp->element;
    queue->front->next = queue->front->next->next;
    if (queue->rear == tmp) queue->rear = queue->front; // 如果队尾是等待出队的节点，队尾需要回到队首的位置上
    free(tmp);
    return e;
}

void PrintHuffmanQueue(LinkedHuffmanQueue queue) {
    HMNode node = queue->front->next;
    while (node) {
        printf("%c ", node->element->element);
        node = node->next;
    }
    printf("\n");
}


HFMTNode createNode(E element, int value) {
    auto node = (HFMTNode) malloc(sizeof(struct HuffmanTreeNode));
    node->element = element;
    node->right = node->left = nullptr;
    node->value = value;
    return node;
}


void testForHuffmanTree() {
    struct HuffmanQueue HFMQueue {};
    initHuffmanQueue(&HFMQueue);

    offerHuffmanQueue(&HFMQueue, createNode('A', 5));
    offerHuffmanQueue(&HFMQueue, createNode('B', 16));
    offerHuffmanQueue(&HFMQueue, createNode('C', 8));
    offerHuffmanQueue(&HFMQueue, createNode('D', 13));

//    PrintHuffmanQueue(&HFMQueue);
    while (HFMQueue.front->next != HFMQueue.rear) {
        HFMTNode left = pollHuffmanQueue(&HFMQueue);
        HFMTNode right = pollHuffmanQueue(&HFMQueue);
        HFMTNode node = createNode(' ', left->value + right->value);
        node->left = left;
        node->right = right;
        offerHuffmanQueue(&HFMQueue, node);
    }

    HFMTNode node = pollHuffmanQueue(&HFMQueue);
    printf("");
}