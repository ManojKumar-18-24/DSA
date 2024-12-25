#include<iostream>
using namespace std;

int y=0;

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

void sort(stack &M,int max,int j)
{ int p=0;
  if(M.top==j)
  {
    push(M,max);y=max;
  }
  else
  {
    int h=pop(M);
    if(h>max){max=h;p++;}      
        sort(M,max,j);
    if(p==1 && h==y ) ;else push(M,h);
  }
}

void reverse(stack &M)
{ static int p=-1;
  if(M.top==p)
  {
    return;
  }
  else
  {
     int g=pop(M);y=g;
     sort(M,g,p);p++;if(y!=g)push(M,g);
     reverse(M);
  }

}

int main()
{
 stack  M;
 M.top=-1;
 M.size=100;
 int n;
 for(int i=1;i<=6;i++){cin>>n;push(M,n);}
 reverse(M);
  while(M.top!=-1)
 {
    cout<<pop(M)<<" ";
 }
return 0;
}