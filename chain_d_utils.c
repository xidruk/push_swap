#include "g_header.h"

// this file contain the utils needed to find the chains in
// linked list and use it


// if sorted returns 1 if not return 0
int check_stack_is_sorted(stack_h *g_stack, int chain_size)
{
    stack_h *current_node;
    stack_h *next_node;
    int chain_index;

    current_node = g_stack;
    chain_index = 0;
    while (current_node && current_node->next_node && chain_index < chain_size)
    {
        next_node = current_node->next_node;
        if (current_node->i_value > next_node->i_value)
            return 0;
        current_node = next_node;
        chain_index++;
    }
    return 1;
}

int get_npts(stack_h *g_stack, int _node_position)
{
    int needed_position;
    int current_position;
    stack_h *current_node;
    stack_h *target_node;

    needed_position = 0;
    current_position = 0;
    current_node = g_stack;
    target_node = NULL;
    while (current_node)
    {
        if (current_position == _node_position)
        {
            target_node = current_node;
            break;
        }
        current_node = current_node->next_node;
        current_position++;
    }
    if (!target_node)
        return -1;
    current_node = g_stack;
    while (current_node)
    {
        if (current_node->i_value < target_node->i_value)
            needed_position++;
        current_node = current_node->next_node;
    }
    return needed_position;
}

int get_nmts(stack_h *g_stack, int _node_position)
{

}


void set_g_stack(stack_h *g_stack, int chain_size) // the global stack
{
    int _index;
    stack_h *current_node;

    _index = 0;
    current_node = g_stack;
    while (current_node)
    {
        current_node->i_index = _index;
        current_node->npts = get_npts(current_node, current_node->i_index);
        current_node->nmts = get_nmts(current_node, current_node->i_index);
        current_node = current_node->next_node;
        _index++;
    }
    
}
