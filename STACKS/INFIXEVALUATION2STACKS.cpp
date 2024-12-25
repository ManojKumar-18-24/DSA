#include<iostream>
#include<cstring>
using namespace std;

struct stack
{
  int size;
  int elements1[100];
  char elements2[100];
  int topi;
  int topch;
};

char peepch(stack &M)
{
   return (M.topch==-1)?-1:M.elements2[M.topch];
}

char popch(stack &M)
{
    return ( M.topch==-1)?-1: M.elements2[M.topch--];
}

void pushch(stack &M,char ch)
{
  if(M.topch==M.size-1);
  else
  { 
    M.topch++;
    M.elements2[M.topch]=ch;
  }
}

int peepint(stack &M)
{
    return (M.topi==-1)?-1:M.elements1[M.topi];
}

int popinter(stack &M)
{
    return ( M.topi==-1)?-1: M.elements1[M.topi--];
}

void pushint(stack &M,int x)
{
  if(M.topi==M.size-1);
  else
  { 
    M.topi++;
    M.elements1[M.topi]=x;
  }
}

int prese(stack &M,char ch)
{
  if(ch=='+' || ch=='-')
  {
    if(peepch(M)=='*'|| '/')
    {
        return false;
    }
    return true;
  }
  if(ch=='*')
  {
     if(peepch(M)=='/')return false;
     return true;
  }
    if(ch=='/')
  {
     if(peepch(M)=='*')return false;
     return true;
  }
}

int main()
{
  stack  M;
 M.topi=-1; M.topch=-1;
 M.size=100;
 string s;cin>>s;int c=1;
 for(int i=0;i<s.length();i++)
 {
    if(s[i]-'0'>=0 && s[i]-'0'<10)
    {
        pushint(M,s[i]-'0');
    }
    else
    {
        if(M.topch!=-1) c=prese(M,s[i]);
       if(c==0)
       {
        while(M.topch!=-1)
        {
            int n=popinter(M),m=popinter(M);
            switch(popch(M))
            {
                case '+':pushint(M,n+m);break;
                case '-':pushint(M,m-n);break;
                case '*':pushint(M,n*m);break;
                case '/':pushint(M,m/n);break;
            }
        }
        pushch(M,s[i]);
       }
       else
       {
        pushch(M,s[i]);
       } 
    }
 }
         while(M.topch!=-1)
        {
            int n=popinter(M),m=popinter(M);
            switch(popch(M))
            {
                case '+':pushint(M,n+m);break;
                case '-':pushint(M,m-n);break;
                case '*':pushint(M,n*m);break;
                case '/':pushint(M,m/n);break;
            }
        }
        cout<<popinter(M);
 return 0;
}