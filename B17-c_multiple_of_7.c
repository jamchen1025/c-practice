/**********************************************************************************
 確認7的倍數不用/和%
 同3的倍數觀念
 2進位bit個別%7會有規律
 1,2,4,1,2,4,...
 **********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int multipleOf7(int num) {
    if (num < 0) num = -num;
    
    if (num == 0 || num == 7) return 1;
    if (num < 7) return 0;
    
    int one = 0, two = 0, three = 0;
    while (num != 0) {
        one += 1 * (num & 1);
        num >>= 1;
        two += 2 * (num & 1);
        num >>= 1;
        three += 4 * (num & 1);
        num >>= 1;
    }
    
    return multipleOf7(one + two + three);
}

int main() {
    printf("%d\n", multipleOf7(32));
    printf("%d\n", multipleOf7(35));
    printf("%d\n", multipleOf7(3577));
    return 0;
}
