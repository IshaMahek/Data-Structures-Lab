
#include<stdio.h>
int fib(int);
int main()
{
int n, m= 0, i;
printf("Enter the limit:");
scanf("%d", &n);
printf("Fibonacci series terms are:");
for(i = 1; i <= n; i++)
{
printf("%d ", fib(m));
m++;
}
return 0;
}
int fib(int n)
{
if(n == 0 || n == 1)
return n;
else
return(fib(n-1) + fib(n-2));
}
