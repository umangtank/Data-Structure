#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void TOH(int n, char s, char i, char d)
{
	static int x=1;
	if(n>0)
	{

		TOH(n-1,s,d,i);
		printf("\n %d %c to %c",x++,s,d);
		TOH(n-1,i,s,d);
	}
}
void main()
{
	int n;
	clrscr();
	printf("\n Enter the value of n: ");
	scanf("%d",&n);
	TOH(n,'a','b','c');
	getch();
}