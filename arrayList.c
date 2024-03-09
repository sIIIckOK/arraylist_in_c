#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* elements;
}ArrayList;

ArrayList* CreateArrayList(int count, ...){
    int capacity = count;
    if (count < 5){
        capacity = 5;
    }
    ArrayList* a = malloc(sizeof(ArrayList)); 
    a->elements = malloc(capacity*sizeof(int));
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        int v = va_arg(args, int);
        a->elements[i] = v;
    }
    a->size = count;
    a->capacity = capacity;
    va_end(args);
    return a;
}

void PrintArrayList(ArrayList* a){
    printf("[ ");
    for (int i = 0; i < a->size; i++){
        printf("%d ", a->elements[i]);
    }
    printf("]\n");
}

void AppendArrayList(ArrayList* a, int v){
    if (a->size+1 > a->capacity){
        a->elements = realloc(a->elements, (a->capacity+1)*sizeof(int));
        a->capacity++;
    }
    a->size++;
    a->elements[a->capacity-1] = v;
}

void ExtendArrayList(ArrayList* a, int count, ...){
    if (a->size+count > a->capacity){
        int factor = a->size+count+3;
        a->elements = realloc(a->elements, (factor)*sizeof(int));
        a->capacity = factor;
    }
    va_list args;
    va_start(args, count);
    for (int i = a->size; i < a->size+count; i++){
        int v = va_arg(args, int);
        a->elements[i] = v;
    } 
    a->size+=count;
    va_end(args);
}

void DeleteElement(ArrayList* a, int index){
    if (a->size-1 < index){
        printf("[Error]: in DeleteElementArrayList index out of bounds\n");
        return;
    }
    for (int i = index; i < a->size-1; i++){
        a->elements[i] = a->elements[i+1];
    }
    a->size--;
}

void ReEvalArrayList(ArrayList* a){
    if (a->size-a->capacity > 5){
        a->elements = realloc(a->elements, (a->size+5)*sizeof(int)); 
        a->capacity = a->size+5;
    }
}

