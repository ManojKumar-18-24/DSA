#include<iostream>
using namespace std;

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

void shift(node* &L)
{
   node* prev=L;
   node* temp=L;int c=0;
  while(1)
   { 
    if(temp->num==-1)break;
    if( c==0 && L!=temp && L->next!=temp)prev=prev->next;
    int n=temp->num;node* s=temp;
    temp=temp->next;
    if(n%2!=0)
    {
       if(s==L){L=prev->next;prev=L;}
       else prev->next=prev->next->next;
       node* temp2=temp;
       while(temp2->next!=NULL)temp2=temp2->next;
       temp2->next=s;
       s->next=NULL;c=1;
    }
    else c=0;
   }     
}

int main()
{
    int n;cin>>n;   
    node* L=new node(n);
    cin>>n;
    while(n!=-1)
    {
       addend(L,n);
       cin>>n;
    }
    addend(L,-1);
    shift(L);
    return 0;
}