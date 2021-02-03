#include <stdio.h>
#include <stdlib.h>

extern void func1(void);
extern void func2(void);
extern void func3(void);
extern void func4(void);
extern void func5(void);

int main() {
  int n = 0;
  //    if n==1 execute func1;
  //    if n==2 execute func2;
  //    if n==3 execute func3;
  //    if n==4 execute func4;
  //    if n==5 execute func5;
  void (*func_array_1[])(void) = {0, func1, func2, func3, func4, func5};
  func_array_1[n]();
  //    if n==33 execute func1; 33%7 = 5
  //    if n==67 execute func2; 67%7 = 4
  //    if n==324 execute func3; 324%7 = 2
  //    if n==231 execute func4; 231%7 = 0
  //    if n==687 execute func5; 687%7 = 1
  void (*func_array_2[])(void) = {func4, func5, func3, 0, func2, func1};
  func_array_2[n]();
  return 0;
}
