#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char a[128];

char merrily_access_out_of_bounds(int i)
{
    return a[i];
}

int merrily_access(int *p)
{
    int r = (rand() % 5);
    printf("Remainder: %d\n", r);
    if (0 == r)
        return *p;
    else
        return 1;
}

int main()
{
    srand(time(NULL));
    for(int i=0; i<129; i++)
        putchar(merrily_access_out_of_bounds(i));
    printf("%d\n", merrily_access(NULL));
}
