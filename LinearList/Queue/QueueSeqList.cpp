//
// Created by 鲍伟 on 2022/8/26.
// 队列 数组
//

typedef int E;

struct QueueSeqList {
    E* array;
    int capacity;
    int front;  // 队头
    int rear;   // 队尾
};

typedef QueueSeqList * ArrayQueue;

bool initQueueSeqList(ArrayQueue queue) {
    queue->array = (E*)malloc(sizeof (E) * 10);
    if (queue->array == nullptr) {
        return false;
    }
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return true;
}

bool offerQueueSeqList(ArrayQueue queue, E element) {
    int pos = (queue->rear + 1) % queue->capacity;
    // 队满
    if (pos == queue->front) return false;
    queue->rear = pos;
    queue->array[queue->rear] =  element;
    return true;
}


bool isEmptyQueueSeqList(ArrayQueue queue) {
    return queue->rear == queue->front;
}


E pollQueueSeqList(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}


void PrintQueueSeqList(ArrayQueue queue) {
    int i = queue->front;
    do {
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    } while (i != queue->rear);
    printf("\n");
}