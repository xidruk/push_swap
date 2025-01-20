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

stack_h *gen_new_item(void)
{
    stack_h *g_stack;

    g_stack = malloc(sizeof(stack_h));
    if (!g_stack)
        return (NULL);

    init_stack_item(g_stack);

    return (g_stack);
}

void update_i_index(stack_h *g_stack , int new_index)
{
    if (!g_stack)
        return ;
    g_stack->i_index = new_index;
}


void update_i_value(stack_h *g_stack , int new_value)
{
    if (!g_stack)
        return ;
    g_stack->i_value = new_value;
}


void update_npts(stack_h *g_stack , int new_npts)
{
    if (!g_stack)
        return ;
    g_stack->npts = new_npts;
}


void update_nmts(stack_h *g_stack , int new_nmts)
{
    if (!g_stack)
        return ;
    g_stack->nmts = new_nmts;
}


void set_stack_to_SA(stack_h *g_stack)
{
    if (!g_stack)
        return ;
    g_stack->stack_id = STACK_A;
}


void set_stack_to_SB(stack_h *g_stack)
{
    if (!g_stack)
        return ;
    g_stack->stack_id = STACK_B;
}

int set_next_node(stack_h *current_node, stack_h *next_node)
{
    if (!current_node || !next_node)
        return 0;
    current_node->next_node = next_node;
    return 1;
}

void free_stack(stack_h *g_stack)
{
    stack_h *temp;
    while (g_stack)
    {
        temp = g_stack;
        g_stack = g_stack->next_node;
        free(temp);
    }
}

stack_h *array_to_linked_list(int *array, int size)
{
    stack_h *head = NULL;       // Pointer to the head of the list
    stack_h *current = NULL;    // Pointer to the current node
    int i = 0;                  // Index for the array

    while (i < size)
    {
        stack_h *new_node = gen_new_item(); // Allocate memory for a new node
        if (!new_node)                     // Check for allocation failure
        {
            free_stack(head);              // Free any already allocated nodes
            return (NULL);                 // Return NULL to indicate failure
        }

        // Set the values for the new node
        update_i_value(new_node, array[i]); // Set the value from the array
        update_i_index(new_node, i);        // Optionally set the index
        set_stack_to_SA(new_node);          // Assign to stack A by default

        if (!head)
            head = new_node;                // Set the head for the first node
            else
                set_next_node(current, new_node); // Link the current node to the new one

                current = new_node;                 // Move to the new node
                i++;                                // Increment the index
    }

    return head; // Return the head of the linked list
}


