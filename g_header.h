#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define STACK_A 'A'
#define STACK_B 'B'

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


// Errors Flags 

#define BAD_FLAG 1
#define SUC_FLAG 0

#define ARGFLAG 1 // argflag (error in the args )
#define MALCTFLAG 2 // malloc allocation fails (error in the args )
#define OVERFLOWFLAG 3 // Over flow error 
#define UNDERFLOWFLAG 4 // under flow error 
#define EUOFNNODE 5 // error under creation of new node (allocation fails)

// Errors functions
void error_center(int flag);

// args helper functions
int *array_allocator(int items_count);
int *init_array(int *array_of_int, char **array_of_strings, int items_count);

// global stack functions
void init_stack_item(stack_h *g_stack);
stack_h *gen_new_item(void);
void update_i_index(stack_h *g_stack , int new_index);
void update_i_value(stack_h *g_stack , int new_value);
void update_npts(stack_h *g_stack , int new_npts);
void update_nmts(stack_h *g_stack , int new_nmts);
void set_stack_to_SA(stack_h *g_stack);
void set_stack_to_SB(stack_h *g_stack);
int set_next_node(stack_h *current_node, stack_h *next_node);
void free_stack(stack_h *g_stack);
stack_h *array_to_linked_list(int *array, int size);

typedef struct list
{
  int i_value; //  item value
  int i_index; // item index
  int npts; // needed poisition to be sorted
  int nmts; // needed moves to be sorted
  char stack_id; // stack id a or b
  struct list *next_node; // pointer to the next node
} stack_h; // stack_h stacl holder


#endif
