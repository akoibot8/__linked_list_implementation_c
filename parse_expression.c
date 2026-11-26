#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse_expression.h"
#include "linked_list_array.h"

/*
 * TODO: Handle the parenthasis case where parenthasis are present within the passed expression
 *	^^ as of right now we just do not allow the handler to pass through an expression containing parenthasis and having to handle the 
 *	case right this instant would result in bad implementation!
 *			Though note the scaffolding for the implemtation is well under way
 *				* Check "parse_expression.h"
 * */


int is_operator(int character)
{
    return strchr("*-+/", character) != NULL;
    //return (char[]){'*', '-', '+', '/'}[character]? 1 : 0;
}

char* is_parenthasis(char character)
{
	if (character == 0)
	{
		printf("You must explicitly pass through a valid character, you passed -> %c\n", character);
		return 0;
	}

	switch (character)
	{
		case '(': return "opening";
		case ')': return "closing";
	}
	return 0;
}

int get_operator_weight(char op)
{ 
    switch (op) {
        case '^':
            return 3;
        case '/':
        case '*': 
            return 2;
        case '-':
        case '+': 
            return 1;
        default: return 0; 
    }
}

int is_of_higher_order(char char_1, char char_2)
{
    return get_operator_weight(char_1) > get_operator_weight(char_2);
}

char* parse_expression(char *expr,int expr_len, char *parse_operation_type)
{
    if (expr == NULL)
    {
        printf("%s\n", "you cannot parse an expression that's null...");
    }
    if (!strcmp(parse_operation_type, "postfix") && !strcmp(parse_operation_type, "prefix"))
    {
        printf("%s\n", "You passed an invalid parse_operation_type!");
    }
   

    linked_list_array* my_array = allocate_linked_list_array();
    char* parsed_expression = malloc(expr_len + 1);
    if (parsed_expression == NULL) return NULL;
    parsed_expression[0] = '\0'; // Initialize as empty string so strcat works safely
    /*
       we are to now scan the expression from L -> R if we want 
       infix notation, else R -> L.
    */
    
    printf("%s %d\n", "string length -> ", expr_len);
    if (!strcmp(parse_operation_type, "postfix"))
    {
        for (int i = 0; i < expr_len;i++)
        {
            if (is_operator(expr[i]))
            {
                while (!is_empty(my_array) && is_of_higher_order(my_array->top->value, expr[i] ))
                {
                    node_t popped = pop(my_array);

                    char __t_pop[] = {popped->value, '\0'};
                    strcat(parsed_expression, __t_pop);
                    free(popped);
                }

                push(my_array, expr[i]);
            } else
            {
                char __t_expr[] = {expr[i], '\0'};
                strcat(parsed_expression, __t_expr);
            }

        }
            
        while (!is_empty(my_array))
        {
            node_t popped = pop(my_array);

            char __t_pop[] = {popped->value, '\0'};
            strcat(parsed_expression, __t_pop);
            free(popped);
        }
    
        return parsed_expression;
    } else 
    {
        return NULL;
    }
}
