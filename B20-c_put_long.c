#include <stdio.h>
#include <stdlib.h>

void my_putlong(long num) {
  if (num < 0) {
    putchar('-');
    my_putlong(-num);
    return;
  }
  if (num > 9) my_putlong(num / 10);  // print higher digits,
  putchar(num % 10 + '0');  // print last digit(mod), ’0′ + will convert to
                            // ASCII printable char.
}

int main() {
  my_putlong(123456789);
  return 0;
}
