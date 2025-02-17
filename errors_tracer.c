#include "g_header.h"

void error_printer(char *data)
{
  int _index;

  _index = 0;
  while (data[_index])
  {
    write (1, &data[_index], 1);
    _index++;
  }
  write (1, "\n", 1);
}

void args_error(void)
{
    write(1, "BAD FLAG [1] ? Error In Given ARGS ! \n", 39);
    exit((int)BAD_FLAG);
}

void malct_error(void)
{
    write(1, "BAD FLAG [2] ? Malloc Fails Under Allocation ! \n", 47);
    exit((int)BAD_FLAG);
}

void overflow_error(void)
{
    write(1, "BAD FLAG [3] ? Overflow Error - Input is too large ! \n", 55);
    exit((int)BAD_FLAG);
}

void underflow_error(void)
{
    write(1, "BAD FLAG [4] ? Underflow Error - Input is too small ! \n", 56);
    exit((int)BAD_FLAG);
}

void fail_to_create_new_node()
{
    write(1, "BAD FLAG [5] ? Failed to Create New Node - Memory Allocation Failed! \n", 71);
    exit((int)BAD_FLAG);
}

void error_is_not_a_number()
{
  error_printer("BAD FLAG [6] ? The Given Param is Not a Number!");
  exit((int)BAD_FLAG);
}

void error_center(int flag)
{
    if (flag == (int)ARGFLAG)
        args_error();
    else if (flag == (int)MALCTFLAG)
        malct_error();
    else if (flag == (int)OVERFLOWFLAG)
        overflow_error();
    else if (flag == (int)UNDERFLOWFLAG)
        underflow_error();
    else if (flag == (int)EUOFNNODE)
        fail_to_create_new_node();
    else if (flag == (int)IS_NOTANUMBER)
      error_is_not_a_number();
}
