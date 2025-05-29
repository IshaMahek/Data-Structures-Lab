#include<stdio.h>
int fact(int n);

void main()
{
int n,i,s;
printf("enter number");
scanf("%d",&n);
s=1;
i=1;
for(i=1;i<=n;i++)
{
	s=s*i;
}
printf("factorial=%d \n",s);




//recursive
printf("after recursion\n");
printf("factorial=%d",fact(n));
}
int fact(int n)
{
if(n==1||n==0)
{
 return 1;
 }
 else
 return n*fact(n-1);
 }
