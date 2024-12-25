#include<iostream>
using namespace std;

struct stack
{
  int size;
  char elements[100];
  int top;
};

void peep(stack &M)
{
    (M.top==-1)?cout<<"empty":cout<<M.elements[M.top]<<" ";
}

char pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
}

void push(stack &M,char ch)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements2[M.top]=ch;
  }
}

int valid(stack &M,string s)
{ 
  
}

int main()
{
 stack  M;
 M.top=-1;
 M.size=100;
 string s;cin>>s;
 cout<<valid(M,s);
return 0;
}
 
