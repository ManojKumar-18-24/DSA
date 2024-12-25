#include<iostream>
using namespace std;

struct stack
{
  int size=100;
  int elements[100];
  int top=-1;
};

int peep(stack &M)
{
    return (M.top==-1)?-1:M.elements[M.top];
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

class node
{   public:
    int num;
    node* next;
    node(int num1)
    {
        num=num1;
        next=NULL;
    }
};

void addend(node* LPTR,int n)
{
  while(LPTR->next!=NULL)
  {
    LPTR=LPTR->next;
  }
  node* L=new node(n);
  LPTR->next=L;
}

void printing(node* LPTR)
{
    while(LPTR)
    {
        cout<<LPTR->num<<" ";
        LPTR=LPTR->next;
    }
}

int palindrome(node* LPTR,stack &M)
{
  node* SP;node* FP;
  SP=LPTR;FP=LPTR; int p=0;
  while(FP)
  {
    if(FP->next==NULL){p++; break;}
    push(M,SP->num);
    SP=SP->next;
    FP=(FP->next)->next;
  }
   if(p>0)SP=SP->next;
   while(SP)
   {
     if(!(SP->num==pop(M)))return 0;
     SP=SP->next;
   }
    return 1;
}

int main()
{
    int n;cin>>n;
    stack M;
    node* LPTR=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(LPTR,n);
        cin>>n;
    }
    cout<<palindrome(LPTR,M);
    return 0;
}
