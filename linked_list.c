#include <stdio.h>
#include <stdlib.h>

#include "./linked_list.h"

// TODO: this needs to be documented again
// checkout the header file.

node_t allocate_node()
{
    return (node*)malloc(sizeof(node));
}

int insert_to_front(node_t* NODE_HEAD, int value)
{
    if (!NODE_HEAD)
    {
        printf("NODE_HEAD; must be explicitly passed via reference");
        return -1;
    }

    if (!value)
    {
        printf("value; must be explicitly passed");
        return -1;
    }

    node_t _t = allocate_node();
    _t->previous = NULL;
    _t->next = *NODE_HEAD;
    _t->value = value;

    (*NODE_HEAD)->previous = _t;
    *NODE_HEAD = _t;

    //printf( "Value -> %-3d | Mem Location -> %p\n",
            //_t->value,(void*)(_t));

    return 0;
}

int insert_to_back(node_t* NODE_HEAD, int value)
{
    if (!NODE_HEAD)
    {
        printf("NODE_HEAD; must be explicitly passed via reference");
        return -1;
    }

    if (!value)
    {
        printf("value; must be explicitly passed");
        return -1;
    }

   
    node_t _t = allocate_node();

    _t->next = NULL;
    _t->previous = NULL;
    _t->value = value;

    node_t current = *NODE_HEAD;

    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = _t;
    _t->previous = current;
    _t->next = NULL;


    return 0;
}

void  __print(node_t* HEAD, int inverse, int __print_as_characters)
{

    node_t current =  *HEAD;

    //printf("%p \n",(void*)current);


    if (inverse) // -> we are allowed to just do this because 0 is falsely in C
    {
        // first count up then print backwards
        while (current->next != NULL)
        {
            current = current->next; // First we must head all the way up
        }
        while (current != NULL)
        {
            printf(__print_as_characters == 1 ? "%c\n" : "%d\n", current->value);
            current = current->previous; // --> then back down and output
        }
    }
    else  // downwards //
    {
        while (current != NULL)
        {
            printf(__print_as_characters == 1 ? "%c\n" : "%d\n", current->value);
            current = current->next; // --> traverse
        }
    }
}


