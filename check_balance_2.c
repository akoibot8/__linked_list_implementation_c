#include "linked_list_array.h"
#include <stdbool.h>
#include <string.h>

/*
    so the plan with this implementation is as follows
        instead of doing all those checks we did as with the other one
        we will instead just push into an array, and check the last with whatever is in the array

        for example

            for all characters in string
                if character is not a valid parenthasis or string is empty automatically return false
                
                if the character is a opening parenthasis or closing parenthasis
                    if the current head of the array is not the closing or opening pair of this character then
                        push the chacter into the array
                    else 
                        pop
                else
                    return false --> its auto just unbalanced.
*/

/*
    TODO: find a better way to determin matching pairs
    FIXME: as of right now the matching pair function doesnt properly work. doesnt seem to reconize
        // ( && ) as matching pairs
*/

int is_matching_pair(char* str_1, char* str_2)
{
    if (*str_2 == 0 || *str_1 == 0)
    {
        return false;
    }

    printf("%s %d\n", "second value", *str_2);
    if (!strcmp(str_1, "("))
    {
        return !strcmp(str_2, ")");
    }
    if (!strcmp(str_1, "{"))
    {
        return !strcmp(str_2, "}");
    }
    if (!strcmp(str_1, "["))
    {
        return !strcmp(str_2, "]");
    }

    /*
       I know this is extreamly unoptimal but we've also gotta watch for the case where str 1 is the closing
       pair.
    */

    if (strcmp(str_1, ")") == 0)
    {
        printf("inside ( \n");
        return strcmp(str_2, "(") == 0;
    }
    if (!strcmp(str_1, "}"))
    {
        return !strcmp(str_2, "{");
    }
    if (!strcmp(str_1, "]"))
    {
        return !strcmp(str_2, "[");
    }

    return false;
}

bool check_balance(const char* str)
{
    
    /*    6      1
       [[]][] + \0
    */
    const int len = strlen(str);
    linked_list_array* array = allocate_linked_list_array();
    
    printf("%s\n", str);
    
    if (!strcmp(str, ""))
    {
        return false;
    }

    if (str == 0)
    {
        return false;
    }

    // minus one to accounbt for  the null terminator
    for (int i = 0; i < len ; i++)
    {
        printf("itter \n");
        printf("%d %d %c\n", i, len, str[i]);
        if (str[i] == '('  ||str[i] == '[' || str[i] == '{' ||
            str[i] == ']' || str[i] == ')' || str['}']
        )
        {

            printf("%s %c %c\n", "before", str[i], array->top->value);
            if (is_matching_pair((char*)&str[i], (char*)&array->top->value))
            {
                printf("%s %c %c\n", "Its a mtaching pair!", str[i], array->top->value);
                pop(array);
            }
            else 
            {

                printf("%s\n", "Pushing");
                push(array, str[i]);
            }
        }
    }

    if (is_empty(array))
    {
        return true;
    }


    return 0;
}
