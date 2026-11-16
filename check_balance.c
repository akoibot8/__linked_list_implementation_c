#include <string.h>
#include "linked_list_array.h"

/*
    horrid function that returns what type of parenthasis the 
    character you just passed is.
*/
char* get_type(char c)
{
    if (c == '[')
    {
        return "osb";
    } 
    else if (c == ']') 
    {
        return "csb";
    }
    else if (c == '(') 
    {
        return "ob";
    }
    else if (c == ')') 
    {
        return "cb";
    }

    return "prob_char";
}

/*
    Checks whether the first char is the equiv oposite of the other char
    @return 0|1 true if so else false
*/
int is_matching_pair(char char_1, char char_2)
{
    const char* typeof_char_1 = get_type(char_1);
    const char* typeof_char_2 = get_type(char_2);
    
    // printf("%s %s\n", "type1 -> ", typeof_char_1);
    // printf("%s %s\n", "type2 -> ", typeof_char_2);

    if(!strcmp(typeof_char_1 , "osb"))
    {
        if (!strcmp(typeof_char_2, "csb"))
        {
            return 1;
        }
    } else if (!strcmp(typeof_char_1, "csb"))
    {
        if (!strcmp(typeof_char_2, "osb"))
        {
            return 1;
        }
    } else if (!strcmp(typeof_char_1, "cb"))
    {
        if (!strcmp(typeof_char_2, "ob"))
        {
            return 1;
        }
    } else if (!strcmp(typeof_char_1, "ob"))
    {
        if (!strcmp(typeof_char_2, "cb"))
        {
            return 1;
        }
    }
    
    /*
        we can just let comparisons between two letters pass
    */
    if (!strcmp(typeof_char_1, "prob_char") 
            && !strcmp(typeof_char_2, "prob_char"))
    {
        return 1;
    }

    return 0;
}

/*
    Checks for a balance of parentasis inside the given string
        NOTE: note that this specific implementation is incredibly impracticle and won't actually work for any complex cases
        as it just checks from the outside edges (0 <-> n) into the middle, this means that its unable to catch cases
        where for example theirs something linke this "()(){}" or "(20) / (2 *100)".
    
    @param const char* str -> the string containing the balance or unbalance of parenthasis you wanna check
    @return 0|1 true if so else false
*/
int __check_balance(const char* str)
{
    linked_list_array* _array = allocate_linked_list_array();
    linked_list_array* _awaiting = allocate_linked_list_array();
    /*
        checking for balanced parentthesis's via linked list arrays

        given a string of a sequence of parentasis, for example -> [()()],
        make sure that all the parenthasis, have a opening (if its closing) or closing (if its opening)
        parenthasis.
        
        The approach im going to take to solve this is as follows
            * first put the individual characters within the list into the array
            * after all the characters are in the array, im then going to go through the array, keeping a reference
            * to the last parentasis, and if its open or closed
    */
    
    //char* str = "[)]";
    if (strcmp(str, "") == 0)
    {
        return 0;
    }


    const int length = strlen(str);
    if (length == 0)
    {
        return 0;
    }
    
    for (int i = 0; i < length; i++)
    {
        push(_array, str[i]);
    }
    
    node_t current_p = _array->top;
    int is_still_valid = 1;
    for (int i = 0; i < (length-1); i++)
    {
        // printf("%s %c\n", "f1 -> ", current_p->value);
        // printf("%s %c\n", "f2 -> ", str[i]);
        if (is_matching_pair(current_p->value,str[i]))
        {

            // printf("%s %c %c \n","matching pair found! -> ", current_p->value,str[i]);

            // printf("%c %c \n", current_p->value, str[i]);
            current_p = current_p->next;
        } else 
        {
            // pop(_array);
            // str[i] = '-';
            is_still_valid = 0;
            // printf("Skibidi dop");
        }

    }
    
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     printf("%s %c \n", "skibidi = ",str[i]);
    // }

    // __print(&_array->top, 0, 1);

    if (is_still_valid) 
    {
        printf("%s %s\n", str, " is balanced!");
        return 1;
    } 
    else 
    {
        printf("%s %s\n", str, " is UNbalanced!");
    }
    return 0;
}
