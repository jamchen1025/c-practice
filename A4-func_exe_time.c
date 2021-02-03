#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a = 0;

void adda()
{
    a++;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    a = 0;
    start = clock();
    for(int i = 0; i < 100000000; i++)
    {
        a++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("1 %f\n", cpu_time_used);

    a = 0;
    start = clock();
    for(int i = 0; i < 100000000; i++)
    {
        adda();
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("2 %f\n", cpu_time_used);

    return 0;
}