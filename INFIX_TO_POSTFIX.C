#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[50],n=50,top=0,val,postfix[50],infix[50];
void push(char data)
{
	if(top>=n)
	{
		printf("\nstack overflow");
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
char pop()
{
	int val;
	if(top==0)
	{
	       printf("\n stack underflow");
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}

int is_operator(char data)
{
	if(data=='*' || data=='-' || data=='*' || data=='/' || data=='^')
	{
		return 1;
	}
}
int precedence(char data)
{
	if(data=='^')
		return 3;
	else if(data=='*' || data=='/')
		return 2;
	else if(data=='+' || data=='-')
		return 1;
	else
		return 0;
}


void main()
{
	int i=0,j=0;
	clrscr();
	printf("\n Ener the expression\n");
	gets(infix);
	while(infix[i]!='\0')
	{
		if(isalpha(infix[i]) || isdigit(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
			i++;
		}
		else if(infix[i]=='(')
		{
			push(infix[i]);
			i++;
																																																																									}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[j]=pop();
				j++;
			}
		top--;
		i++;
		}
	else
	{
		while(precedence(stack[top])>=precedence(infix[i]))
		{
		postfix[j]=pop();
		j++;
		}
	 push(infix[i]);
	 i++;
	}
}
while(top>0)
{
	postfix[j]=pop();
	j++;
}
postfix[j]='\0';
printf("\ninfix=\n");
puts(infix);
printf("\npostfix=\n");
puts(postfix);
getch();
}