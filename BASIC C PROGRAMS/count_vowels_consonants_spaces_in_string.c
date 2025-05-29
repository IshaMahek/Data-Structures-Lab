#include<stdio.h>
#include<string.h>
void main()
{
char w[120];
int len,i,s,v,c;
printf("enter string:");
fgets(w,120,stdin);
len=strlen(w);
i=0;
c=0;
s=0;
while(i<len)
{
if(w[i]=='a' ||w[i]=='e' ||w[i]=='i' ||w[i]=='o' ||w[i]=='u' ||w[i]=='A' ||w[i]=='E' ||w[i]=='I' ||w[i]=='O' ||w[i]=='U' )
{
v++;

}
else if(w[i]==' ')
{
s++;
}
else if(w[i]>='a' && w[i]<='z' || w[i] >= 'A'  && w[i]<='Z'
)
{
c++;
}

i++;
}
printf("vowels=%d,consonants=%d,spaces=%d",v,c,s);
}
