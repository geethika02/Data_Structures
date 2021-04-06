//infix to postfix
#include<bits/stdc++.h>
#define max 1000
using namespace std;
int Stack[max];
int top=-1;
int isempty()
{
	if(top==-1)
      return 1;
    else
    return 0;
}
int priority(char c)
{
	if(c=='(')
	return -1;
	if(c=='+')
	return 0;
	if(c=='-')
	return 1;
	if(c=='*')
	return 2;
	if(c=='/')
	return 3;
	if(c=='^')
	return 4;	
}
void push(char c)
{
	top=top+1;
	Stack[top]=c;
}
char pop()
{
	if(!isempty())

	{
	char s;
	s=Stack[top];
	top=top-1;
	return s;
}
}

int main()
{
	string s;
	int i,j;
	cin>>s;
	for(i=0;s[i]!='\0';i++)
	{
	if(s[i]>='a' && s[i]<='z')
	{
	   cout<<s[i];
	}
	else if(s[i]=='(')
		push(s[i]);
	else if(s[i]==')')
	{
		char r=pop();
		while(r!='(' ){
			cout<<r;
			r=pop();
		}
	}
	else
	{
		if(priority(s[i])>priority(Stack[top]))
		{
			push(s[i]);
		}
                                 else{
		while(priority(s[i])<priority(Stack[top]) && Stack[top]!='(')
		{
			char c=pop();
			cout<<c;
		}
	push(s[i]);	
	}
           }
}
	while(!isempty())
	{
		cout<<pop();
	}
}
