#include <stdio.h>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main() {
  int a = 10, b = 5;

  printf("Addition: %d\n", add(a, b));
  printf("Subtraction: %d\n", subtract(a, b));
  printf("Multiplication: %d\n", multiply(a, b));
  printf("Division: %d\n", divide(a, b));

  return 0;
}