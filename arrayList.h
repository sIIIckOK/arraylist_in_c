#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* elements;
}ArrayList;

ArrayList* CreateArrayList(int count, ...);

void PrintArrayList(ArrayList* a);

void AppendArrayList(ArrayList* a, int v);

void ExtendArrayList(ArrayList* a, int count, ...);

void DeleteElement(ArrayList* a, int index);

void ReEvalArrayList(ArrayList* a);

