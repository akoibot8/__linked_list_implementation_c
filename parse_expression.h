#ifndef __PARSE_EXPRESSION_H
#define __PARSE_EXPRESSION_H

/*
    essentially how this will work is that you will be passed an expression that's something along the lines of
    for example "2+3+4*2", this is one of the more simple expressions that doesnt require us to think about 
    parenthasis. in the more complex cases you would get for example "((2+2)*2)/2", in that case we would have to pay
    heed to the parenthasis because they dictate how the operations are carried out
*/


/*
    parses the passed (string)expression according to the parse_operation_type.
    @param expr string -> the expression that is to be parsed.
    @param expr_len int -> length of the string
    @param parse_operation_type string -> "postfix" | "prefix"  NOTE: we automatically just assume that the parse type is infix by default
    @return expr string -> the parsed expression
*/
char* parse_expression(char* expr,int expr_len,char* parse_operation_type); 


/*
    simply returns true or false depending on whether or not the given character is
    ^^ considered an operator. the current operators are just the defaults used by the internet
    *,-,+,/
    @param character int -> the character to check
*/
int is_operator(int character);

/*
    checks if char one is of higher orer to char two.
    by higer order im just talking about bedmas order, for example, according to bedmas the order is as follows
    brackets -> exponets -> multiplication -> division -> adition -> subtraction
       ()   -->   ^     -->       *       -->    /    -->   +    -->     -
    
    @param char_1 char -> the first character, prob HEAD -> this must be checked first because it must go from highest to lowers and one of higher may already be on the stack
    @param char_1 char -> the second character, str[n] 
*/
int is_of_higher_order(char char_1, char char_2);

/*
    gets the weight of the given operator string in regards to bedmas
    @param op char -> the operator
    @return int -> a number telling you the strength of this operator in regards to bedmas
                    Higher = stronger
*/
int get_operator_weight(char op);

#endif
