#pragma once
#include <stdio.h>
#include <stdlib.h>

// Unlike cpp everthings essentially just public

/*  __mem__layout
    in our case a node is comprised of 22 bytes,
    In C, a pointer is always 8 bytes that is when refering to modern 64 bit architecture,
    we have, 2 of these pointers (one for traversing backwards and the other for going foward).
    An interger value is always stored as 4 bytes (32 bits)

    8 
    --- +
    8
    --- +
    4
    --- 
     == 22
    
     NOTE: the compiler might also buffer as for reason's it only knows 
           so in reality we might actually end up takng 

           24 bits ^^^.
*/
typedef struct node
{
    struct node* next; 
    struct node* previous;

    int value;

} node;

typedef node* node_t;


/**
    Allocates memory for a node.
    :WARN: A node takes up 
**/
node_t allocate_node();

/*
   int, according to this function is a testament to whether or not
   we failed to insert. (0 == success, -1 == failure)

   the NODE_HEAD must be passed via reference &
*/
int insert_to_front(node_t* NODE_HEAD, int value);

/*
   prints what ever is inside the given linked list
   NOTE: that head must be passed via reference.
   
   you may also chooose how the list will be dispayed through the inverse booolean
*/
void  __print(node_t* HEAD,int inverse);
