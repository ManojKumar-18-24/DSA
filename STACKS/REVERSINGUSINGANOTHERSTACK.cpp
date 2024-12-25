#include<iostream>
#include<algorithm>
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

void push(stack &M,int x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void set(stack &M,stack &S,int n)
{ 
    int g=pop(S);
    if(n<=g){push(S,g);push(S,n);}
    else if(S.top==-1){push(S,n);push(S,g);}
    else{
    set(M,S,n);
    push(S,g);}
}

void reversestack(stack &M,stack &S,int n,int p=0)
{
  if(M.top==-1)
  {
    if(n>peep(S))
    {
      set(M,S,n);
    }
    return ;
  }
  else if(p==0)
  {
     n=pop(M);
    if(n<=peep(S)){push(S,n);}
    else{p++;}
    reversestack(M,S,n,p);
  }
  else
  {
    set(M,S,n);
    p--; 
     reversestack(M,S,n,p);
  }
}

int main()
{
 stack  M,S;
 M.top=-1;
 M.size=100;
 S.top=-1;
 S.size=100;
 int n;cin>>n;
 while(n!=-1)
 {
   if(n!=-1)
   {
    push(M,n);
   }
   else break;

   cin>>n;
 }
 push(S,pop(M));
 reversestack(M,S,0);
 while(S.top!=-1)
 {
    cout<<pop(S)<<" ";
 }
return 0;
}