#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

/*
    Check the Implementation file (../__linked_list_implementation_c/linked_list_array.c)
    for documentation regarding the motive of this file

    ------------
    Also check @(../__linked_list_implementation_c/linked_list.c)
    for the documentation regading the linked list library we will be using here.
*/

typedef struct 
{
   node_t top;
   int size;

} linked_list_array;

/*
    creates a new linked_list_array
*/
linked_list_array* allocate_linked_list_array();

/*
   pushes to a given linked list array
   by push, I mean that it will push to the front.
*/
int push(linked_list_array* array, int value);

/*
    pops the top of the given linked list array
*/
node_t pop(linked_list_array* array);


