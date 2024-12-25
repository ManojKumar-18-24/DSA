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

void reverse(node* &head)
{
  node* temp2=head->next;
  node* temp3=temp2->next;
  head->next=NULL;
   while(temp3)
   {
     temp2->next=head;
     head=temp2;
     temp2=temp3;
     temp3=temp3->next;
   }
    temp2->next=head;
    head=temp2;
}

int checkpal(node* LPTR)
{
  node* SP;node* FP,* temp;
  SP=LPTR;FP=LPTR; int p=0;
  if(FP->next==NULL)return 1;
  while(FP)
  {
    if(FP->next==NULL){p++; break;};
    temp=SP;
    SP=SP->next;
    FP=(FP->next)->next;
  }
  if(p>0)
  {
     reverse(SP);
  }
  else
  {
    SP=temp; reverse(SP);
  }
  while(LPTR!=SP)
  {
    if(LPTR->num==SP->num);
    else return 0;
    LPTR=LPTR->next;SP=SP->next;
    if(LPTR==NULL)break;
  }
  return 1;
}

int main()
{
    int n;cin>>n;
    node* LPTR=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(LPTR,n);
        cin>>n;
    }
   cout<<checkpal(LPTR);
    return 0;
}