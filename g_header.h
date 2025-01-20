#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define STACK_A 'A'
#define STACK_B 'B'


typedef struct list
{
  int i_value; //  item value
  int i_index; // item index
  int npts; // needed poisition to be sorted
  int nmts; // needed moves to be sorted
  char stack_id; // stack id a or b
  struct list *next_node; // pointer to the next node
} stack_h; // stack_h stacl holder

extern stack_h g_stack; // gobal stack 

#endif
