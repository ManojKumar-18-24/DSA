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
 /*stack  M;
 M.top=-1;
 M.size=100;
 //int n;cin>>n;
 push(M,'(');
 cout<<pop(M);*/
 char ch=')';
 string h=to_string(ch);
 cout<<h;
return 0;
}