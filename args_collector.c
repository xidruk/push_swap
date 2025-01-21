#include "g_header.h"

int *array_allocator(int items_count)
{
    int _init_v;
    int _index;
    int *array;

    _index = 0;
    _init_v = 0;
    array = malloc(items_count * sizeof(int));
    if (!array)
        error_center(MALCTFLAG);
    while (_index < items_count) // initialize the array by 0 to delete the garbedg
    {
        array[_index] = _init_v;
        _index++;
    }
    return (array);
}


int swap_t(const char *str) // swap types
{
    unsigned long result;
    int sign;
    int i;
    int digit;

    i = 0;
    sign = 1;
    result = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        digit = str[i] - '0';
        if (sign == 1 && (result > (MAX_INT / 10) || (result == (MAX_INT / 10) && digit > 7)))
            error_center(OVERFLOWFLAG);
        if (sign == -1 && (result > (unsigned long)(-(MIN_INT / 10)) || (result == (unsigned long)(-(MIN_INT / 10)) && digit > 8)))
            error_center(UNDERFLOWFLAG);
        result = result * 10 + digit;
        i++;
    }
    return (int)(result * sign);
}

int *init_array(int *array_of_int, char **array_of_strings, int items_count)
{
    int _index;
    int tmp_v; // tmp value

    _index = 0;
    tmp_v = 0;
    while (_index < items_count)
    {
        tmp_v = swap_t(array_of_strings[_index + 1]);
        array_of_int[_index] = tmp_v;
        _index++;
    }
    return (array_of_int);
}
