#include<iostream>
#include<cstring>
using namespace std;

struct stack
{
  int size=100;
  char elements[100];
  int top=-1;
};

char peep(stack &M)
{
   return (M.top==-1)?'0':M.elements[M.top];
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
    if(s[i]=='(')
    {  
        push(M,s[i]);
    }
    else
    {
         if(s[i]==')')
        {
            if(pop(M)=='(');
            else{i=-1;break;}
        }
    } i++;
  }
  while(M.top!=-1){i=-1;pop(M);}
  if(i==-1)return false;
  return true;
}

int substring_generator(stack &M,string s)
{ int c=0;
    for(int i=0;i<s.length()-1;i++)
    {
        for(int j=i+1;j<s.length();j++)
        {
          string p=s.substr(i,j-i+1);
          if(valid(M,p))
          {
            if(j-i+1>c)
            {
                c=j-i+1;
            }
          }
        }
    }
    return c;
}

int main()
{
 stack  M;
 string s;cin>>s;s.erase(s.length()-1,1);
 cout<<substring_generator(M,s);
return 0;
}
