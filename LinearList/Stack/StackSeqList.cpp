//
// Created by 鲍伟 on 2022/8/23.
// 栈 (顺序表实现)
//

#include<cstdlib>

typedef int E;

struct Stack {
    E* array;
    int capacity;
    int top;
};

typedef struct Stack * ArrayStack;

bool initStack(ArrayStack stack) {
    stack->array = (E*)malloc(sizeof(E) * 10);
    if (stack->array == nullptr) return false;
    stack->capacity = 10;
    stack->top = -1;
    return true;
}


bool PushStack(ArrayStack stack, E element) {
    // 扩容
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        E* newArray = (E*)realloc(stack->array, newCapacity * sizeof (E));
        if(newArray == nullptr) return false;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return true;
}


bool isStackEmpty(ArrayStack stack) {
    return stack->top == -1;
}

int PopStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

void PrintStack(ArrayStack stack) {
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}