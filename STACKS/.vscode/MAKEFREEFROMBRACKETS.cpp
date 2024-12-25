#include<iostream>
using namespace std;

struct stack
{
  int size=100;
  char elements[100];
  int top=-1;
};

char peep(stack &M)
{
   return (M.top==-1)?'q':M.elements[M.top];
}

char pop(stack &M)
{
    return ( M.top==-1)?'q': M.elements[M.top--];
}

void push(stack &M,char x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void make_free(stack &M,string s)
{
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            if(s[i-1]=='-') c++;
            push(M,s[i]);
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            if( i>1 && s[i-1]=='(')
            {
             if(c%2==0)
             {
                cout<<"+"<<s[i]; 
             }
             else
             {
                cout<<"-"<<s[i];
             }
            }
            else
            {
                if(i>0 && s[i-1]=='+')
                {
                    if(c%2==0)
                     {
                        cout<<"+"<<s[i]; 
                     }
                    else
                     {
                       cout<<"-"<<s[i];
                     }                    
                }
                else if(i>0 && s[i-1]=='-')
                {
                    if(c%2==1)
                     {
                        cout<<"+"<<s[i]; 
                     }
                    else
                     {
                       cout<<"-"<<s[i];
                     }                    
                }
                else
                {
                    cout<<s[i];
                }
            }
        }
        else if(s[i]==')')
        {
            pop(M);
            if(c==1)c--;
        }
    }
}

int main()
{   stack M;
    string s;
    cin>>s;
    if(s[0]=='(')
    {
        s.erase(0,1);
        s.erase(s.length()-1,1);
    }
    make_free(M,s);
}
