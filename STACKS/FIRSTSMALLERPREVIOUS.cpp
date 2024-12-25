#include<iostream>
#include<algorithm>
using namespace std;

struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
};

int peep(stack &M)
{
     return (M.top==-1)?-1:M.elements[M.top];
}

int pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
}

void push(stack &M,int x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void fpss(stack &M,int n)
{
  if(M.top==-1)
  {
      cout<<-1<<" ";
  }
  else
  {
    int m=pop(M);
    if(m>=n)fpss(M,n);
    else cout<<m<<" ";
    push(M,m);
  }
}

void fps(stack &M)
{
    if(M.top==0)
    {
       cout<<-1<<" ";
    }
    else
    {
        int n=pop(M);
        fps(M);
        push(M,n);
        fpss(M,n);
    }
}

int main()
{
 stack  M;
 int c=0;
 int n;cin>>n;
 while(n!=-1)
 {
   push(M,n);
   cin>>n;
 }
 fps(M);
return 0;
}
