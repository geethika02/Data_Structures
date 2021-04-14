#include <iostream>
    using namespace std;
    int top;
    void  check (char str[ ], int n, char stack [ ])
    {
        for(int i = 0 ; i < n ; i++ )
        {
            if (str [ i ] == '(')
            {
                top = top + 1;
                stack[ top ] =  '(';
            }
            if(str[ i ] == ')' )
            {
                if(top == -1 )
                {
                    top = top -1 ;
                    break ;
                 }
                else
                {
                     top = top -1 ;
                }
            }
        }
        if(top == -1)
            cout << "Parenthesis is balanced!" << endl;
        else
            cout << "Parenthesis is not balanced!" << endl ;
    }

    int main ( ) 
    {
        int n;
        cin>>n;
        char s[n];
        cin>>s;
        char stack [ n ] ;
        top = -1;   
        check(s,n,stack);
        return 0;

    } 
