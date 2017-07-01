#include<stdio.h>

int f1(int a) {
  return 1;
}
int f2(int a) {
  return 2;
}
int f3(int a) {
  return a;
}
int main()
{
  typedef int (*fptr)(int);
  fptr a[] = {f1, f2, f3};
  printf("%d%d%d%d", a[0](0), a[1](1), a[2](2), a[2](3));
  return 1;
}