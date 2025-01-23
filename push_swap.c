#include "g_header.h"

int main(int argc, char **argv)
{
    int *array_h; // array holder to holde the Given numbers
    stack_h *head; // the head

    if (argc < 2)
        error_center(ARGFLAG);
    array_h = array_allocator(argc);
    array_h = init_array(array_h, argv, argc - 1);

    head = array_to_linked_list(array_h, argc - 1);
    // set_g_stack(head, argc - 1);
    // stack_h *current_node;
    // current_node = head;
    // while (current_node)
    // {
    //     printf("| %d | %d | %d |\n", current_node->i_index, current_node->npts, current_node->i_value);
    //     current_node = current_node->next_node;
    // }
    //
    return (0);
}
