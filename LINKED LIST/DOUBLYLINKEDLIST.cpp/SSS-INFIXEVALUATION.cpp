#include<iostream>
using namespace std;

class dnode
{
  public:
  dnode* left;
  int flag;
  int data;
  dnode* right;
  dnode(int m)
    {
     left=NULL;
     right=NULL;
     data=m;
    }
};

void print(dnode* D)
{
  while(D!=NULL)
  {
    if(D->data=='+')cout<<'+'<<" ";
    else if(D->data=='-')cout<<'-'<<" ";
    else if(D->data=='*')cout<<"* ";
    else  cout<<D->data<<" ";
    D=D->right;
  }
  cout<<endl;
}

void addfront(dnode* &D,int n)
{
  dnode* g=new dnode(n);
  if(D==NULL){D=g;return;}
  g->right=D;
  D->left=g;
  g->left=D;
  D=g;
}

void addend(dnode* D,int n)
{
  while(D->right!=NULL)
  {
   D=D->right;
  }
  dnode* g=new dnode(n);
  D->right=g;
  g->left=D;
}

int deletefront(dnode* &D)
{
   if(D->right==NULL)
     {
        D=NULL;
        return -1;
      }
   int n=D->data;
   D=D->right;
   D->left->right=NULL;
   D->left=NULL;
   return n;
}

int deleteend(dnode* D)
{
  if(D->right==NULL)
     {
        D=NULL;
        return 0;
      }
  while(D->right->right!=NULL)
  {
     D=D->right;
  }
  int n=D->right->data;
  D->right->left=NULL;
  D->right=NULL;
  return n;
}

int evaluate(int n,int m,char x)
{
    switch(x)
    {
        case '+':return m+n;
        case '-':return n-m;
        case '*':return m*n;
    }
    return 0;
}

int precedence(char lower,char upper)
{
  if(lower=='+' || lower=='-') return false;
  if(lower=='*' && upper!='*') return true;
  return 0;
}

int main()
{
    string s;
    cin>>s;
    dnode * head=new dnode(-1);
    for(int i=0;i<s.length()-1;i++)
    {
        
       if(s[i]>='0')
       {
         addfront(head,s[i]-'0');
       }
       else
       {
         if(s[i]=='/')
         {
            int n=deletefront(head);
            int k=s[i+1]-'0';
            int m=n/k;
            addfront(head,m);
            i++;
         }
         else
         {
            int n=deleteend(head);
            if(n==-1)
            {
                addend(head,-1);
                addend(head,s[i]);
            }
            else
            {
              if(precedence(n,s[i]))
              {
                addend(head,'*');
                while(1)
                {
                   int m=deletefront(head);
                   int n=deletefront(head);
                    if(n==-1)
                     { 
                       addfront(head,-1);
                       addfront(head,m);
                       addend(head,s[i]);
                       break;
                     }
                   char f=deleteend(head);
                   addfront(head,evaluate(n,m,f));
                }
              }
              else
              {
                addend(head,n);addend(head,s[i]);
              }  
            }
         }
       }
    }
                while(1)
                {
                   int m=deletefront(head);
                   int n=deletefront(head);
                    if(n==-1)
                     { 
                       addfront(head,-1);
                       addfront(head,m);break;
                     }
                   char f=deleteend(head);
                   addfront(head,evaluate(n,m,f));
                }
    cout<<deletefront(head);
    return 0;
}