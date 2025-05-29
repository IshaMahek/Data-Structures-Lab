#include<stdio.h>
int main()
	{
		int n, num, sum = 0, rem;
		printf("Enter a number: ");
		scanf("%d",&n);
		num = n;
		while(num!=0)
			{
				rem = num%10;
				sum = sum + rem*rem*rem;
				num = num/10;
			}
		if(n==sum)
			{
				printf("%d is armstrong.",n);
			}
		else
			{
				printf("%d is not armstrong.",n);
			}
		return 0;
	}
