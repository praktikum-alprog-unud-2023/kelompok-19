#include <stdio.h>

int fibonacci(int n) {
   if (n == 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return (fibonacci(n - 1) + fibonacci(n - 2));
   }
}

int main() {
   int n;
	
   printf("Enter a number: ");
   scanf("%d", &n);
   
    if (n < 0) {
      printf("Please enter a non-negative number.\n");
    } else {}
   for (int i = 0; i < n; i++) {
      printf("%d ", fibonacci(i));
   }
   
   printf("\n");
   return 0;
}