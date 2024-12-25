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

int main()
{
 stack  M,S;
 int n;cin>>n;
 while(n!=-1)
 {
    push(M,n);
   cin>>n;
 }
 int p=M.top;
 for(int i=0;i<=p;i++)
 {
    while(M.top!=i)
    { 
     int n=pop(M),m=pop(M);
     if(n>m)
     {
       push(S,m);push(M,n);  
     }
     else
     {
        push(S,n);push(M,m);  
     }
    }
    while(S.top!=-1)
    {
        push(M,pop(S));
    }
 }
 while(M.top!=-1)
 {
    cout<<pop(M)<<" ";
 }
return 0;
}