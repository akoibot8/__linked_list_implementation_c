#include <string.h>
#include <stdio.h>
#include "parse_expression.h"

int main()
{
    char* my_expression = "2+1/2";
    char* my_parsed_expression = parse_expression(my_expression, strlen(my_expression), "postfix");
    
    printf("%s %s\n" ,"parsed expression -> ", my_parsed_expression);

    return 0;
}
