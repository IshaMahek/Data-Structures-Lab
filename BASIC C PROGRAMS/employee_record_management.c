#include<stdio.h>
struct employee
{
    int salary;
    float id;
    char name[25];
}
emp[100];

void main()
{
	struct employee emp[100];
    int i,n;
    printf("Enter the no of employees\n");
    scanf("%d",&n);
    
    printf("Enter employee info\n");
    for(i=0;i<n;i++)
    {
    	printf("\nEnter details :\n");
   	 	printf("ID :");            
   	 	scanf("%f",&emp[i].id);
    	printf("Name :");          
    	scanf("%s",emp[i].name);
    	printf("Salary :");        
    	scanf("%d",&emp[i].salary);
    }
    printf("\nEmployee ID\tEmployee Name\tEmployee Salary\n");
    for(i=0;i<n;i++)
    {
printf("%f\t\t%s\t\t%d\n",emp[i].id,emp[i].name,emp[i].salary);
    }
}






