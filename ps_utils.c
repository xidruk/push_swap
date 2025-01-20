#include "g_header.h"

// defaut stack is a

void init_stack_item(stack_h *g_stack)
{
    if (!g_stack)
        return ;
    g_stack->i_value = 0;
    g_stack->i_index = 0;
    g_stack->npts = 0;
    g_stack->nmts = 0;
    g_stack->stack_id = STACK_A;
    g_stack->next_node = NULL;
}

// generate new item 

stack_h gen_new_item(void)
{
    stack_h g_stack;

    init_stack_item(g_stack);

    return g_stack;
}