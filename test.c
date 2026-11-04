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
node_t allocate_node()
{
    return (node*)malloc(sizeof(node));
}

/*
   int, according to this function is a testament to whether or not
   we failed to insert. (0 == success, -1 == failure)

   the NODE_HEAD must be passed via reference &
*/
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

    printf( "Value -> %-3d | Mem Location -> %p\n",
            _t->value,(void*)(_t));

    return 0;
}

/*
   prints what ever is inside the given linked list
   NOTE: that head must be passed via reference.
   
   you may also chooose how the list will be dispayed through the inverse booolean
*/
void  __print(node_t* HEAD,int inverse)
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
            printf("%d\n", current->value);
            current = current->previous; // --> then back down and output
        }
    }
    else  // downwards //
    {
        while (current != NULL)
        {
            printf("%d\n", current->value);
            current = current->next; // --> traverse
        }
    }
}


/*
   Standered entry point
*/
int main()
{

    node* HEAD = allocate_node(); // WARNING: THIS IS ALWAYS ZERO!
    insert_to_front(&HEAD, 2);
    insert_to_front(&HEAD, 3);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);
    insert_to_front(&HEAD, 4);

    /*  NOTE:
        We know that HEAD is always overwritten whenever
        we insert to front... in our case right here HEAD would be 4,
        or atleast this should be the case.
    */
    
    __print(&HEAD, 1);

    return 0;
}

