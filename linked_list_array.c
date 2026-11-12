#include <stdio.h>
#include <stdlib.h>

#include "./linked_list_array.h"

#include "linked_list.h"

/*
    A linked list implementation of an array structure.
    We've chosen to go with linked list's because they will allow for better mobility
    when it comes to running into memory issues
    
    for example, In a normal array implementation, your confined to 
    the amount of memory that you choose to allocate at edit time, if you wish
    to create more memory for yourself you must then manually release the current memory
    your holding and copy your structure somewhere that allows for a mem strip large enough for your structure
    in our case since we have inked list's our array can be as big as it neeeds as it doesnt need an uncuut long strip of memory
    
           HEAD    NODE 1   NODE 2  NODE 3  TAIL
            # <---> # <----> # <----> <----> # 


    The above in our case is better becauuuse it allows for allot of flexibility when it comes to storing as much data within our structure as we need
    


        WARNING: drawbacks 
              The main one of these being ::SIZE::
              the chains within the linked lists are NOT FREE!
*/

linked_list_array* allocate_linked_list_array()
{
    linked_list_array* _a = (linked_list_array*)malloc(sizeof(linked_list_array));
    _a->top = allocate_node();
    return _a;
}

int push(linked_list_array* array, int value)
{
    if (array == NULL)
    {
        printf("You must explicitly pass a list");
        return 1;
    }

    if (array->top)
    {
        insert_to_front(&array->top, value);
    } else
    {
        printf("%s\n", "theirs no top");
    }

    return 0;
}

node_t pop(linked_list_array* array)
{
    if (array == NULL)
    {
        printf("You must explicitly pass a list");
        return NULL;
    }

    if (array->top)
    {
        node_t __to_be_new_head = allocate_node();
        __to_be_new_head = array->top->next;

        __to_be_new_head->previous = NULL;
        array->top = NULL;

        return __to_be_new_head;
    }

    
    return NULL;
}

