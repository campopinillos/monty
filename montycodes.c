#include "monty.h"

void mop_pall(stack_t **dlinkedlist, unsigned int line_num)
{
    if (dlinkedlist == NULL)
        return;
    else
    {
        print_dlinkedlist(*dlinkedlist);
    }
    
}
