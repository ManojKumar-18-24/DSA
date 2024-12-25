
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int num)
    {
        data=num;
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
{ int  count=0;
    while(count!=6)
    {
        cout<<LPTR->data<<" ";
        LPTR=LPTR->next;
        count++;
    } cout<<endl;
}

void link(node* LPTR)
{
  node* temp=LPTR;
  while(LPTR->next!=NULL)
  {
    LPTR=LPTR->next;
  }
  LPTR->next=temp;
}

node* set(node* head,node* temp)
{
    node* temp1=head;
  while(temp1->next!=temp)
  { 
    temp1=temp1->next;
  }
   return temp1;
}

int main()
{
    int n;cin>>n;
    node* head=new node(1);int i=2;
    while(i<=n){ addend(head,i);i++;}
    link(head);
    node* temp=head;
    int count=0;
    while(1)
    {
        if(count>0)
        {
            if(temp=temp->next)break;
            count=0;
           for(int i=1;i<=2;i++)
           { 
               set(head,temp)->next=temp->next;
               temp=temp->next;
            if(temp==temp->next){cout<<temp->data;break;}
           }
        }
        else
        {
            count++;
            temp=temp->next;
        }
    }
    return 0;
}
