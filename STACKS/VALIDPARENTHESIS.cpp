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

void push(stack &M,int x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

int valid(stack &M,string s)
{ 
  int i=0;
  while(i<s.length())
  {
    if(s[i]=='['||s[i]=='{'||s[i]=='(')
    {  if(i==s.length()-1)return 0;
        push(M,s[i]);
    }
    else
    {
        if(s[i]==']')
        {
            if(pop(M)=='[');
            else return false;
        }
        if(s[i]=='}')
        {
            if(pop(M)=='{');
            else return false;
        }
         if(s[i]==')')
        {
            if(pop(M)=='(');
            else return false;
        }
    } i++;
  }
  return true;
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