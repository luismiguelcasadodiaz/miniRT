#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double ale = rand();
    printf("RAND_MAX = %d, my rand = %f entre 1 y 0 = %f\n", RAND_MAX/2, ale, ale/RAND_MAX);
    return (0);
}