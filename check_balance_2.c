#include "linked_list_array.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
    TODO:
    right now, strings like "<(>) count as balanced strings because we really only care about the parenthasis..."
    Its fine for now but I don't know if thats the right way to go about it.
    ^^^ FIXED -> they are now just also counted as brackets

    FIXME: as of right now the matching pair function doesnt properly work. doesnt seem to reconize
        // ( && ) as matching pairs

*/

/*
    note you must always pass open before close
*/
int is_matching_pair(char open, char close)
{

    switch (open) {
        case '(':
              return (close == ')');
        case '[':
              return (close == ']');
        case '{':
              return (close == '}');
        case '<':
              return (close == '>');
        default: return false;
    };
}


bool check_balance(const char* str)
{
    /*    6      1
       [[]][] + \0
    */

    if (str == NULL)
    {
        printf("%s\n", "the passed string is NULL");
        return false;
    }
    
    if (!strcmp(str, ""))
    {
        return true; // may as well count it as a pass because theirs no unbalance here...
    }
    //printf("Let pass -> %s \n", str);

    const int len = strlen(str);
    linked_list_array* array = allocate_linked_list_array();
    

    // minus one to accounbt for  the null terminator
    for (int i = 0; i < len ; i++)
    {

        if (str[i] == '('  ||str[i] == '[' || str[i] == '{' || str[i] == '<') // it can only ever be the opening pairs
        {
            push(array, str[i]);
        } 
        else if (str[i] == ')'  ||str[i] == ']' || str[i] == '}' || str[i] == '>')
        {
            
            /* 
               Is empty can't be passed here because we
               got a closing char.. but the opened char array is empty..
            */
            if (is_empty(array) || !is_matching_pair(array->top->value, str[i]))
            {
                printf("Failed -> %s\n", str);
                return false;
            }
            node_t popped = pop(array);
            free(popped);
        } 

    }
    if (is_empty(array))
    {
        printf("Passed -> %s\n", str);
        return true;
    }
    else 
    {
        return false;
    }
}
