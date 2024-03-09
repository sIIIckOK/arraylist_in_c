#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* elements;
}ArrayList;

ArrayList* AL_CreateArrayList(int count, ...);

void AL_PrintArrayList(ArrayList* a);

void AL_AppendArrayList(ArrayList* a, int v);

void AL_ExtendArrayList(ArrayList* a, int count, ...);

void AL_DeleteElement(ArrayList* a, int index);

void AL_ReEvalArrayList(ArrayList* a);

