#include <stdio.h>

int fibonacciRecursive(int n) {
   if (n == 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return (fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2));
   }
}
int fibonacciIterative(int n) {
  int t1 = 0, t2 = 1;
  
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    for (int i = 1; i < n; ++i) {
      int nextTerm = t1 + t2;
      t1 = t2;
      t2 = nextTerm;
    }
    return t2;
  }
}

int main() {
   int n;
	
   printf("Enter the number of terms: ");
   scanf("%d", &n);
   
   if (n < 0) {
      printf("Please enter a non-negative number.\n");
   } else {
      printf("Fibonacci Series (Recursive): ");
      for (int i = 0; i < n; i++) {
         printf("%d ", fibonacciRecursive(i));
      }
      printf("\n");

      printf("Fibonacci Series (Iterative): ");
      for (int i = 0; i < n; i++) {
         printf("%d ", fibonacciIterative(i));
      }
      printf("\n");
   }
   
   return 0;
}