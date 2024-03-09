#include <stdio.h>
#include "arrayList.h"

/*
typedef struct {
    size_t size; //size of the array, aka the used-capacity
    size_t capacity; //total capacity of the array
    int* elements; //the array itself
}ArrayList;
*/

int main(){
    //CreateArrayList: creates array list
    //ArrayList*(int number_of_elements, ...elements)<variadic>
    ArrayList* a = CreateArrayList(3, 1, 2, 3);
    printf("Created an Array List: \n");

    //PrintArrayList: prints the array list
    PrintArrayList(a);

    //AppendArrayList: appends an element to an array list
    //void (ArrayList*, int v)
    AppendArrayList(a, 4);
    printf("Appended 4 to an Array List: \n");
    PrintArrayList(a);

    //ExtendArrayList: extend multiple elements to an array list
    //void (ArrayList*, int number_of_elements, ...elements)<variadic>
    //automatically re-allocates memory if needed
    ExtendArrayList(a, 3, 5, 6, 7);
    printf("Appended (5, 6, 7) an Array List: \n");
    PrintArrayList(a);

    //DeleteElement: delete and element from array list (by index)
    //void (ArrayList*, int index_of_element)
    DeleteElement(a, 3);
    printf("Appended (5, 6, 7) an Array List: \n");
    PrintArrayList(a);

    //ReEvalArrayList: revaluates the linked lists 
    //removes extra unused space in the list
    //void 
    ReEvalArrayList(a);
}
