#include "g_header.h"

int main(int argc, char **argv)
{
    int *array_h; // array holder to holde the Given numbers

    if (argc != 101 && argc != 501)
        error_center(ARGFLAG);
    if (argc == 101 || argc == 501)
        array_h = array_allocator(argc);
    array_h = init_array(array_h, argv, argc - 1);

    int index = 0;
    while (index < argc - 1)
    {
        printf("%d", array_h[index]);
        printf(" | ");
        index++;
    }
    
    return (0);
}