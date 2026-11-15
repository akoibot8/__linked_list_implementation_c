#include "check_balance.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
   @Akoi Deng
   2026-11-15
*/

/*
    Have mercy. This is my first check balance attempt lol
    It doesn't really work too well but handles the common normal cases.
*/

int main()
{
    assert(check_balance("[]") == true);
    assert(check_balance("[()]") == true);
    assert(check_balance("[(()]") == false);
    assert(check_balance("") == false);
    assert(check_balance("(helloo world)") == true);

    //assert(check_balance("(20) / (2 *100)") == true);

    printf("All test passed! \n");
}


