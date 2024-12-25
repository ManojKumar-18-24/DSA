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

void peepch(stack &M)
{
    (M.topch==-1)?cout<<"empty":cout<<M.elements2[M.topch]<<" ";
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

void peepint(stack &M)
{
    (M.topi==-1)?cout<<"empty":cout<<M.elements1[M.topi]<<" ";
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

int valid(stack &M,string s)
{ 
  int i=0;
  while(i<s.length())
  {
    if(s[i]=='['||s[i]=='{'||s[i]=='(')
    {  if(i==s.length()-1)return 0;
        pushch(M,s[i]);
    }
    else
    {
        if(s[i]==']')
        {
            if(popch(M)=='[');
            else return false;
        }
        if(s[i]=='}')
        {
            if(popch(M)=='{');
            else return false;
        }
         if(s[i]==')')
        {
            if(popch(M)=='(');
            else return false;
        }
    } i++;
  }
  return true;
}

int postfix(stack &M,string s)
{
 int i=0,h;
 while(i<s.length())
 {
   if(s[i]-48>=0 && s[i]-48<=9)
   {
     h=s[i]-48;
    pushint(M,h);
   }
   else
   {
    switch(s[i])
    {
        case '+':h=M.elements1[M.topi]+M.elements1[M.topi-1];popinter(M);
                 popinter(M);pushint(M,h);break;
     case '-':h=M.elements1[M.topi-1]-M.elements1[M.topi];popinter(M);
                 popinter(M);pushint(M,h); break;
     case '*':h=M.elements1[M.topi]*M.elements1[M.topi-1];popinter(M);
                 popinter(M);pushint(M,h);break;
    case '/':h=M.elements1[M.topi-1]/M.elements1[M.topi];popinter(M);
                 popinter(M);pushint(M,h);break;                       
    }
   }
   i++;
 }
 return M.elements1[M.topi];
}

int main()
{
  stack  M;
 M.topi=-1; M.topch=-1;
 M.size=100;
 int n,sum=0;cin>>n;string s,p;cin>>s>>p;
// while(n>0){sum=(sum)*10+n%10;n/=10;}
 while(n>0){pushint(M,n%10);n/=10;}
 while(1){if(M.topi==-1)break;cout<<popinter(M)<<" ";}cout<<endl;
  s.erase(s.length()-1,1);
  cout<<valid(M,s)<<endl;
 M.topch=-1;M.topi=-1; 
 p.erase(p.length()-1,1);
 cout<<postfix(M,p);
return 0;
}