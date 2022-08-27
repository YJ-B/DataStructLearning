//
// Created by 鲍伟 on 2022/8/22.
// 顺序表 -> 数组形式存储
//
#include <cstdlib>
typedef int E;

struct List {
    E * array;    // 表示数组
    int capacity;   // 表示容量
    int size;   // 表示长度
};

typedef struct List * ArrayList;

bool initSeqList(ArrayList list) {
    list->array = (E*)malloc(sizeof(E) * 10);
    if (list->array == nullptr) return false;
    list -> capacity = 10;
    list->size = 0;
    return true;
}

bool insertSeqList(ArrayList list, E element, int index) {
    if (index > list->size + 1 || index < 1) {
        return false;
    }
    // 超出空间 扩容
    if (list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);   // 右移1位
        E * newArray = (E*)realloc(list->array, newCapacity * sizeof(E));
        if (newArray == nullptr) {
            return false;
        }
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; i--) {
        list->array[i] = list->array[i-1];
    }
    list->array[index - 1] = element;
    list->size++;
    return true;
}

bool deleteSeqList(ArrayList list, int index) {
    if (index < 1 || index > list->size + 1) return false;
    for (int i = index - 1; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return true;
}

int sizeSeqList(ArrayList list) {
    return list->size;
}

E* getSeqList(ArrayList list, int index) {
    // 超出范围返回nullptr
    if (index < 1 || index > list->size) return nullptr;
    return &list->array[index-1];
}

int findSeqList(ArrayList list, E element) {
    for (int i = 0; i< list->size; ++i) {
        if (list->array[i] == element) {
            return i + 1;
        }
    }
    return -1;
}

void printSeqList(ArrayList list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}