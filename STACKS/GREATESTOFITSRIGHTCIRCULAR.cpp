#include<iostream>
#include<algorithm>
using namespace std;

struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
};

int c=0,k=0;

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

void does(stack &M,int r)
{  static int e=0,d=-1,f=-1;
   if(M.top==-1)
   {
     if(k>0) cout<<d<<" ";
     else cout<<f<<" ";
     k=0;d=-1;f=-1;
      e++;
   }
   else if(M.top==e)
   {
       int m=pop(M);
       does(M,r);
       push(M,m);
   }
   else 
   {
    
    int m=pop(M);
    if(M.top>=e)
    {
        if(m>r)
        {
          k++;d=m;
        }
    }
    else
    {
        if(m>r)
        {
            f=m;
        }
    }
    does(M,r);
    push(M,m);   
   }
}

void call(stack M)
{
    static int p=-1;
    if(M.top==p)
    {
       p++;
    }
    else
    {
        int m=pop(M);
        c=m;
        call(M);
        push(M,m);
    }
}

int main()
{
 stack  M;
 int n;cin>>n;
 while(n!=-1)
 {
   push(M,n);
   cin>>n;
 }
 for(int i=0;i<=M.top;i++)
 {
   call(M);
   does(M,c);
 }
return 0;
}
