#include "g_header.h"


// this file conatin the needed fucntion to pars a data given by the user


int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int validate_number(char *data)
{
    int _index;

    _index = 0;
    while (data[_index])
    {
        if (!is_number(data[_index]))
            error_center(IS_NOTANUMBER);
        _index++;
    }
    return (1);
}
