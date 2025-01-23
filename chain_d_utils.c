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

// int validate_chain(stack_h *g_stack)
// {
//
// }

// int get_npts(stack_h *g_stack, int _node_position)
// {
//     if (!g_stack) // Handle empty list case
//         return -1;
//
//     stack_h *target_node = NULL;
//     stack_h *current_node = g_stack;
//     int current_position = 0;
//     int needed_position = 0;
//
//     // Locate the target node based on its position
//     while (current_node)
//     {
//         if (current_position == _node_position)
//         {
//             target_node = current_node;
//             break;
//         }
//         current_node = current_node->next_node;
//         current_position++;
//     }
//
//     // If the target node is not found, return -1
//     if (!target_node)
//         return -1;
//
//     // Reset traversal to calculate needed position
//     current_node = g_stack;
//     while (current_node)
//     {
//         // If current_node value is less than target_node, increment needed_position
//         if (current_node->i_value < target_node->i_value)
//         {
//             needed_position++;
//         }
//         // If values are equal, use index as a tie-breaker
//         else if (current_node->i_value == target_node->i_value &&
//                  current_node->i_index < target_node->i_index)
//         {
//             needed_position++;
//         }
//         current_node = current_node->next_node;
//     }
//
//     return needed_position;
// }
//


// int get_nmts(stack_h *g_stack, int _node_position)
// {

// }


// void set_g_stack(stack_h *g_stack, int chain_size) // the global stack
// {
//     int _index;
//     stack_h *current_node;
//
//     _index = 0;
//     current_node = g_stack;
//     while (current_node)
//     {
//         // current_node->i_index = _index; alredy seted
//         current_node->npts = get_npts(current_node, current_node->i_index);
//         //current_node->nmts = get_nmts(current_node, current_node->i_index);
//         current_node = current_node->next_node;
//         _index++;
//     }
//
// }
