#include<iostream>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

void peep(stack &M)
{
    (M.top==-1)?cout<<"empty":cout<<M.elements[M.top]<<" ";
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
 M.top=-1;S.top=-1;
 M.size=100;S.size=100;
 int n;cin>>n;int max=n,min=n;
while(n!=-1)
{
    if(n>max){max=n;}
    if(n<min){min=n;}
    push(M,n);push(S,min);push(S,max);
    cin>>n;
}
while(M.top!=-1)cout<<pop(M)<<" ";
while(S.top!=-1)cout<<pop(S)<<" ";
return 0;
}