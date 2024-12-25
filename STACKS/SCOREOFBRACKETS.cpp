#include<iostream>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

int peep(stack &M)
{
   return (M.top==-1)?-1:M.elements[M.top];
}

int pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
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


int main()
{
 stack  M;
 M.top=-1;
 M.size=100;
 string s;cin>>s;
 for(int i=0;i<s.length();i++)
 {
    if(M.top>=1)
    {
        int n=pop(M),m=pop(M);
        if(n!=40 && m!=40)
        {
            push(M,n+m);
        }
        else
        {
            push(M,m);push(M,n);
        }
    }
    if(s[i]=='(')
    {
        push(M,s[i]);
    }
    else if(s[i]==')')
    {
        if(peep(M)=='(')
        {
            pop(M);push(M,1);
        }
        else
        {
          int h=pop(M);
          if(pop(M)=='(')
          {
            push(M,2*h);
          }
        }
    }
 }
    
     if(M.top>=1)
    {
        int n=pop(M),m=pop(M);//cout<<n<<" "<<" "<<endl;
        push(M,n+m);    
    }
    cout<<pop(M);
return 0;
}