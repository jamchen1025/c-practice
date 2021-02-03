#include <stdio.h>
#include <stdlib.h>

typedef unsigned char   U8;
typedef unsigned short  U16;
typedef unsigned int    U32;
typedef unsigned long long      U64;
U8 gub_num_of_lbn_per_page = 4;

typedef union _scramble_frame_ctrl
{
    struct
    {
        U16 frame_addr: 8;
        U16 length: 8;
    } bytes;
    U16 AsU16;
} SCRAMBLE_FRAME_CTRL;

int main()
{
    int i = 0;
    int a[] = {1, 2, 3, 4, 5};
    a[i++] = 0;

    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    


    return 0;
}