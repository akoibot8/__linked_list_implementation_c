cmake_minimum_required(VERSION 3.15)
project(c_testing C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(balance_test
    check_balance_2.c
    test_balance.c
    linked_list.c
    linked_list_array.c
)

add_executable(expression_test
    _test_parse_expression.c
    parse_expression.c
    linked_list.c
    linked_list_array.c
)
