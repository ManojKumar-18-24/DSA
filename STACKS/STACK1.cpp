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
 stack  M;
 M.top=-1;
 M.size=100;
 int n;cin>>n;
 while(n!=-1)
 {
   if(n==1)
   {
    int x;cout<<"enter";cin>>x;push(M,x);cout<<M.top<<" ";
   }
   if(n==2)
   {
    cout<<pop(M)<<" ";cout<<M.top<<" ";
   }
   if(n==3)
   {
    peep(M);
   }
   cin>>n;
 }
 
return 0;
}