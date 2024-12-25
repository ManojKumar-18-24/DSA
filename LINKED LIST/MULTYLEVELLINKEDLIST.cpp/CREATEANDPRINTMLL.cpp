#include<iostream>
using namespace std;

class node
{
 public:
 int data;
 node* next;
 node(int n)
 {
    data=n;
    next=NULL;
 }
};

class M
{
  public:
  int data;
  node* down;
  M* next;
  M(int n)
  {
    data=n;
    down=NULL;
    next=NULL;
  }
};

M* addend(M* head,int n)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    M* g=new M(n);
    head->next=g;
   return g;
}

void addendnode(M* tail,int n)
{
    node* temp=tail->down;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node * g=new node(n);
    temp->next=g;
}

void print(M* head)
{
 while(head!=NULL)
 {
    cout<<head->data<<" ";
    node* temp=head->down;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=head->next;
 }
}

int main()
{
  int n;
  cin>>n;
 M* head=new M(n);
 M* tail=head;
 cin>>n;
 while(n!=-2)
 {
   while(n==0)
   {
    cin>>n;if(n==-2)break;
    tail=addend(head,n);
    cin>>n;
   }
   if(n==1)
   {
    cin>>n;
    node* t=new node(n);
    tail->down=t;
    cin>>n;
    while(n!=-1)
    {
     addendnode(tail,n);cin>>n;
    }
   }
   if(n==-2)break;
   cin>>n;
   if(n==-2)break;
   tail=addend(head,n);
   cin>>n;
 }
 print(head);
return 0;
}