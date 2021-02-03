#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void test(int num)
{
    int array[num];
    for (int i = 0; i < num; ++i)
    {
        array[i] = i;
    }

    for (int i = 0; i < num; ++i)
    {
        printf("%d\n", array[i]);
    }
}
int main()
{
    int a;
    srand(time(NULL));
    a= (rand()%100)+1;
    test(a);

    // int a[2][4];
    // printf("%x\n", (int) sizeof(int) * 4);
    // printf("%x\n", (int) sizeof(a));
    // printf("%x\n", (int) &a[0]);
    // printf("%x\n", (int) &a[1]);
    // int ad = (int) &a[0];
    // int bd = (int) &a[1];
    // printf("%x\n", bd - ad);
    return 0;
}