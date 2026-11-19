#include "check_balance.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 1. Core Basics & Empty Strings
    assert(check_balance("") == true);
    assert(check_balance("hello world 123!@#") == true);

    // 2. Essential Failure Modes (All 4 bracket types)
    assert(check_balance("<") == false);
    assert(check_balance(">") == false);
    assert(check_balance("(>") == false);
    assert(check_balance("<]") == false);
    assert(check_balance("><") == false);
    assert(check_balance("<(>)") == false); // Interleaved / crossing with <>

    // 3. Structural Deception (4-Way Nesting & Deceptive Shapes)
    assert(check_balance("(()))(") == false);              // Equal counts, dips negative mid-way
    assert(check_balance("<({[}>])") == false);            // Symmetric lookalike, invalid LIFO order
    assert(check_balance("<[({)}]>") == false);            // 4-way interleaved crossing
    assert(check_balance("<(([]){})>[([<{}>])]") == true); // Deep 4-bracket tree

    // 4. ASCII Boundary Traps
    // '<' is 60, '=' is 61, '>' is 62 | '[' is 91, '\' is 92, ']' is 93 | '{' is 123, '|' is 124, '}' is 125
    assert(check_balance("<=") == false); // '=' (61) sits right between '<' (60) and '>' (62)!
    assert(check_balance("[\\") == false);
    assert(check_balance("{|") == false);
    assert(check_balance("<=>(\\[\\{\\|}])") == true);

    // 5. C-String & Memory Edge Cases
    assert(check_balance(NULL) == false);   // Guard against NULL pointer dereference
    assert(check_balance("<(\0)>") == false); // Embedded null terminator cuts string short
    assert(check_balance("<>\0<") == true);   // Garbage after '\0' must be ignored

    // 6. Real-World Code / Generic Template Syntax (Using <> as template/tag brackets)
    const char *template_snippet = 
        "std::map<std::string, std::vector<int>> data;\n"
        "int (*func_ptr)(int[], char*) = &my_func;\n"
        "if (arr[(i + 1) * 2] != '\\0') { return (void*)0; }";
    assert(check_balance(template_snippet) == true);

    // 7. Dynamic Stack Capacity Test (Breaks fixed-size arrays like char stack)
    int depth = 5000;
    char *deep = malloc(depth * 2 + 1);
    if (deep) {
        memset(deep, '<', depth);
        memset(deep + depth, '>', depth);
        deep[depth * 2] = '\0';
        assert(check_balance(deep) == true);

        deep[depth] = ']'; // Corrupt center closing bracket
        assert(check_balance(deep) == false);
        free(deep);
    }

    printf("All Test Passed!!!\n");
    return 0;
}

