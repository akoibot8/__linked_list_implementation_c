#include <stdio.h>
#include <stdlib.h>

#include "linked_list_array.h"
#include "linked_list.h"

/*
   Standered entry point
*/
int main()
{
    linked_list_array* my_linked_list_array = allocate_linked_list_array();
    
    
    push(my_linked_list_array, 1);
    push(my_linked_list_array, 2);
    push(my_linked_list_array, 3);
    push(my_linked_list_array, 4);

    __print(&my_linked_list_array->top, 1, 0);


    /*  NOTE:
        We know that HEAD is always overwritten whenever
        we insert to front... in our case right here HEAD would be 4,
        or atleast this should be the case.
    */
    

    return 0;
}
