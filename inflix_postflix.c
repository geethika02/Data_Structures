#include<stdio.h>

#include<stdlib.h>

#define MAX 1005

 
char stack[MAX];

 int top=-1;

 
int priority(char a)
{

	if(a=='(')
	
      return -1;

	if(a=='+')
	
      return 0;

	if(a=='-')

	    return 1;
	
  if(a=='*')

	    return 2;

	if(a=='/')

	    return 3;

	if(a=='^')

	     return 4;
}

 
void push(char a)
{

	if(top==MAX-1)

	return;

	else

	{

		top=top+1;

		stack[top]=a;

	}
}

 
char pop()
{

	if(top==-1)

	return 1;

	else

	{

		char val=stack[top];

		top=top-1;

		return val;

	}
}

 
int isempty()
{

	if(top==-1)

	return 1;

	else

	return 0;
}

 
char str[MAX];

 
int main()
{

	scanf("%s",str);

	int i;

	for(i=0;str[i]!='\0';i++)

	{

		if(str[i]>='a'&&str[i]<='z')

		printf("%c",str[i]);

		else if(str[i]=='(')

		push(str[i]);

		else if(str[i]==')')

		{

			char c=pop();

			//printf("---%c",c);

			while(c!='(')

			{

				printf("%c",c);

				c=pop();

			}

		}

		else
 
		{

		if(priority(str[i])>priority(stack[top]))

		push(str[i]);

		else

		{

		 while(priority(str[i])<priority(stack[top])&&stack[top]!='(')

		 {

		 	char c=pop();

		 	printf("%c",c);

		 }

		 push(str[i]);

		}

		}

	}

	while(!isempty())

	{

		printf("%c",pop());

	}
	
	return 0;

}
