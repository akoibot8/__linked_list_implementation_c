#include <stdio.h>
#include <stdlib.h>

#include "./linked_list.h"

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
