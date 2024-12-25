#include<iostream>
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
    return ( M.top==-1)?'0': M.elements[M.top--];
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

void eval(stack &M,string s)
{ int p;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]==')')
    {   char h,g,m;
        while(M.top!=-1)
        {
            h=pop(M);g=pop(M);m=pop(M);
            switch(g)
            {
                case '+': p=(m-48)+(h-48);p+=48;push(M,p);break;
                case '-': p=(m-48)-(h-48);p+=48;push(M,p);break;
                case '*': p=(m-48)*(h-48);p+=48;push(M,p);break;
                case '/': p=(m-48)/(h-48);p+=48;push(M,p);break;
            } 
            p=pop(M);
            if(peep(M)=='('){pop(M);push(M,p);break;}push(M,p);
        }
    }
    else if(s[i]=='*'|| s[i]=='/')
    {   push(M,s[i]);
        while(s[i+1]=='*' || s[i+1]=='/' ||(s[i+1]-'0'>=0 && s[i+1]-'0'<10))
        {
            push(M,s[i+1]);
            i++;
        } 
        if(s[i+1]=='('){continue;}
         char h,g,m;
        while(M.top!=-1)
        {
            h=pop(M);g=pop(M);m=pop(M);  
            switch(g)
            {
                case '+': p=(m-48)+(h-48);p+=48;push(M,p);break;
                case '-': p=(m-48)-(h-48);p+=48;push(M,p);break;
                case '*': p=(m-48)*(h-48);p+=48;push(M,p);break;
                case '/': p=(m-48)/(h-48);p+=48;push(M,p);break;
            } p=pop(M);
            if(M.top==-1 || peep(M)=='('){push(M,p);break;}push(M,p);
        }
        h=pop(M);pop(M);push(M,h);    
    }
    else
    {
        push(M,s[i]);
    }
  }
        char h,g,m;
        while(M.top>=2)
        {
            h=pop(M);g=pop(M);m=pop(M);
            if(g=='(')break;
            switch(g)
            {
                case '+': p=(m-48)+(h-48);p+=48;push(M,p);break;
                case '-': p=(m-48)-(h-48);p+=48;push(M,p);break;
                case '*': p=(m-48)*(h-48);p+=48;push(M,p);break;
                case '/': p=(m-48)/(h-48);p+=48;push(M,p);break;
            }
            p=pop(M);
            if(M.top==-1 || peep(M)=='('){push(M,p);break;}push(M,p);   
        }
        cout<<p-48<<endl;
}

void quicksort_iteration(int a[],stack &S,int n)
{
  int left=0,right=n-1,pivot=left;
  while(1)
  {
   
  }
}

int main()
{
 stack  M,S;
 string s;cout<<"enter string: ";cin>>s;
 eval(M,s);
 int n;cout<<"ENTER SIZE OF ARRAY: ";
 int a[n];for(int i=0;i<n;i++){cout<<"a["<<i<<"] = ";cin>>a[i];}
 quicksort_iteration(a,S,n);
return 0;
}