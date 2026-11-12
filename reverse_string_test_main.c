#include <string.h>
#include "./linked_list.h"



node_t string_to_linked_list(node_t HEAD, const char str[], const int length, int _rev)
{
    
    if (HEAD == NULL)
    {
        return 0; // It's fine to return 0 in this case because node_t is a pointer (a digit) anyway.
                  // 0 In our case wiill just mean failure.
    }

    if (str == NULL)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {

        // node_t temp = allocate_node();
        // temp->value = str[i];
        // temp->previous = current;
        // temp->next = NULL;
        // current->next = temp;
        // current = temp; 

        _rev? insert_to_back(&HEAD, str[i]) 
            : insert_to_front(&HEAD, str[i]);
    }
    
    //printf("%d\n", HEAD->value);
    return HEAD;
}

int main()
{
    
    node_t HEAD = allocate_node();
    const char our_string[] = "Hello";
    const int length = strlen(our_string);

    node_t head_to_our_string_list = string_to_linked_list(HEAD, our_string, length, 1);
    //printf("%c\n", head_to_our_string_list->value);
    
    //printf("%c\n", 111);
    __print(&head_to_our_string_list,0, 1);

    return 0;
}
