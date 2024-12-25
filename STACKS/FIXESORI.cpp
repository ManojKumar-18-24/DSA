#include<iostream>
using namespace std;

struct stack
{
  int size=100;
  string elements[100];
  int top=-1;
};

string peep(stack &M)
{
    return (M.top==-1)?"":M.elements[M.top];
}

string pop(stack &M)
{
    return ( M.top==-1)?"": M.elements[M.top--];
}

void push(stack &M,string x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

void infixtoprefix(stack&M,string s)
{
  
}

void prefixtoinfix(stack &M,stack &S,string s)
{  int c=0;
  for(int i=0;i<s.length();i++)
  {  
    if(c>=2)
    {
      while(S.top!=0)
       {
        string r=pop(S),q=pop(S),p=pop(M);
        if(r.length()>1)
        {
            r="("+r+")";
        }
        if(q.length()>1)
        {
            q="("+q+")";
        } 
        push(S,q+p+r);
       }  
    }
    if(s[i]>='A' && s[i]<='Z')
    { string h;h+=s[i];
        push(S,h);c++;
    }
    else
    {  string h;h+=s[i];
        push(M,h);
        c=0;
    }
  }
      while(S.top!=0)
       {
        string r=pop(S),q=pop(S),p=pop(M);
       if(r.length()>1)
        {
            r="("+r+")";
        }
        if(q.length()>1)
        {
            q="("+q+")";
        } 
         push(S,q+p+r);
       } 
       cout<<pop(S);
}

void prefixtopostfix(stack &M,stack&S,string s)
{ int c=0;
  for(int i=0;i<s.length();i++)
  {  
    if(c>=2)
    {
      while(S.top!=0)
       {
        string r=pop(S),q=pop(S),p=pop(M);
         push(S,q+r+p);
       }  
    }
    if(s[i]>='A' && s[i]<='Z')
    { string h;h+=s[i];
        push(S,h);c++;
    }
    else
    {  string h;h+=s[i];
        push(M,h);
        c=0;
    }
  }
      while(S.top!=0)
       {
        string r=pop(S),q=pop(S),p=pop(M);
         push(S,q+r+p);
       } 
       cout<<pop(S);
}

void postfixtoinfix(stack&M,string s)
{
    for(int i=0;i<s.length();i++)
   {
     if(s[i]>='A'&& s[i]<='Z')
     {  string h;h+=s[i];
        push(M,h);
     }
     else
     {   string h;h+=s[i];
        string r=pop(M),q=pop(M),p;
        if(r.length()>1)
        {
            r="("+r+")";
        }
        if(q.length()>1)
        {
            q="("+q+")";
        } 
       p=q+h+r;
       push(M,p);
     }
 }
 cout<<pop(M);
}

void postfixtoprefix(stack &M,string s)
{
    for(int i=0;i<s.length();i++)
    {
      if(s[i]>='A'&& s[i]<='Z')
     {  string h;h+=s[i];
        push(M,h);
     }
     else
     {   string h;h+=s[i];
        string r=pop(M),q=pop(M),p;
       p=h+q+r;
       push(M,p);
     }       
    }
    cout<<pop(M);
}

int main()
{
 stack  M,S;
 string s;cin>>s;
 //postfixtoinfix(M,s);
 //postfixtoprefix(M,s);
 //prefixtopostfix(M,S,s); REVERSE
 //prefixtoinfix(M,S,s);
return 0;
}