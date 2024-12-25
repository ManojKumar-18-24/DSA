#include<iostream>
using namespace std;

struct stack
{
  int size;
  char elements[100];
  int top;
};
int c=0;
char peep(stack &M)
{
   return (M.top==-1)?'q':M.elements[M.top];
}

char pop(stack &M)
{
    return ( M.top==-1)?'q': M.elements[M.top--];
}

void push(stack &M,char x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void count(string s,stack&M)
{  
   static int i=0,c=0;
  if(s.length()==i)cout<<c;
  else if( i<s.length()-1 && s[i]=='(' && s[i+1]==')')
  {
    c++;i+=2; count(s,M);
  }
  else if(i<s.length()-2 && s[i]=='(' && s[i+2]==')' && s[i+1]!='(')
  {
     c++;i+=3; count(s,M);
  }
  else if(s[i]=='(')
  {
    push(M,s[i]);
    if(s[i+1]=='(')
    {
      push(M,'.');
    }
    i++; count(s,M);
  }
  else if(s[i]==')')
  {
    char ch = pop(M);
    if(i+1<s.length() && s[i+1]==')')
    { int p=0;
      if(M.top!=-1)
      {
        ch=pop(M);
        if(ch=='.')c++;
        else{p++;}
      }
      if(i+2<s.length() && s[i+2]==')'){p++;}
      if(M.top!=-1 && p==0)
      {
        ch=pop(M);
      }
    }
    else
    { 
        ch=pop(M);if(peep(M)=='.')ch=pop(M);            
    }  i++;count(s,M); 
  }
  else
  {
    i++; count(s,M);
  }
 
}
int main()
{
 stack  M;
 M.top=-1;
 M.size=100;
 string s;cin>>s;
count(s,M);
return 0;
}