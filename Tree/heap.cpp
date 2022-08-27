//
// Created by 鲍伟 on 2022/8/26.
// 大根堆 小根堆
// 一般使用数组存储，以大顶堆为例
//

typedef int E;
typedef struct MaxHeap {
    E * arr;
    int size;
    int capacity;
} * Heap;

bool initHeap(Heap heap) {
    heap->size = 0;
    heap->capacity = 10;
    heap->arr = (E*)malloc(sizeof(E) * heap->capacity);
    return heap->arr != nullptr;
}

bool insertMaxHeap(Heap heap, E element) {
    if (heap->size == heap->capacity) {
        // 扩容
        int newCapacity = heap->capacity + (heap->capacity >> 1);
        E * newArray = (E*) realloc(heap->arr, newCapacity * sizeof(E));
        if (newArray == nullptr) return false;
        heap->arr = newArray;
        heap->capacity = newCapacity;
    }
    int index = ++heap->size;
    while (index > 1 && element > heap->arr[index/2]) {
        heap->arr[index] = heap->arr[index/2];
        index /= 2;
    }
    heap->arr[index] = element;
    return true;
}

// 返回最大值 == 堆排序
E deleteMaxHeap(Heap heap) {
    E max = heap->arr[1];
    E e = heap->arr[heap->size--];
    int index = 1;
    while (index * 2 < heap->size) {
        // 从上往下找
        int child = index * 2;  // 左孩子
        // 左孩子右孩子选一个大的
        if (child < heap->size && heap->arr[child] < heap->arr[child + 1]) {
            child += 1;
        }
        if (e >= heap->arr[child]) break;   // 如果子节点都不大于新节点，那么说明就是这个位置，可以直接结束
        else heap->arr[index] = heap->arr[child];   // 否则堆化
        index = child;
    }
    heap->arr[index] = e; // 找到位置，放进去
    return max;
}

void PrintMaxHeap(Heap heap) {
    for (int i = 1; i <= heap->size; ++i) {
        printf("%d ", heap->arr[i]);
    }
}


void testForMaxHeap() {
    struct MaxHeap heap {};
    initHeap(&heap);

    insertMaxHeap(&heap, 5);
    insertMaxHeap(&heap, 2);
    insertMaxHeap(&heap, 3);
    insertMaxHeap(&heap, 7);
    insertMaxHeap(&heap, 6);

//    PrintMaxHeap(&heap);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", deleteMaxHeap(&heap));
    }
}