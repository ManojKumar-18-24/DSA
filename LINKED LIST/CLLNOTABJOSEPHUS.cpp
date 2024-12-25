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
    node* head=new node(n);cin>>n;
    while(n!=-1){   addend(head,n);cin>>n;}
    cin>>n;
    link(head);
    node* temp=head;
    int count=0;
    while(1)
    {
        if(count==n-1)
        {
             if(temp==temp->next)break;
            cout<<temp->data<<" ";
            count=0;
            set(head,temp)->next=temp->next;
            temp=temp->next;
        }
        else
        {
            count++;
            temp=temp->next;
        }
    }
    return 0;
}