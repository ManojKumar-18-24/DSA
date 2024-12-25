#include<bits/stdc++.h>
using namespace std;

class node
{ public:
  int num;
  node* ptr;
  node(int data)
  {
    num=data;
    ptr=NULL;
  }
};

void addend(node* LPTR,int n)
{
  while(LPTR->ptr!=NULL)
  {
    LPTR=LPTR->ptr;
  }
  node* L=new node(n);
  LPTR->ptr=L;
}

void print(node* head)
{
 node* temp=head;
 while(temp!=NULL) { cout<<temp->num<<" "; temp=temp->ptr;}
 cout<<endl;
}

void reverse(node* &head)
{
  if(head==NULL || head->ptr==NULL)return ;
  node* temp2=head->ptr;
  node* temp3=temp2->ptr;
  head->ptr=NULL;
   while(temp3)
   {
     temp2->ptr=head;
     head=temp2;
     temp2=temp3;
     temp3=temp3->ptr;
   }
    temp2->ptr=head;
    head=temp2;
}

int main()
{
  int p;cin>>p;
  node* head=new node(p);cin>>p;
  while(p!=-1)
  {
    addend(head,p);
    cin>>p;
  }
  cout<<head->num<<endl;
  reverse(head);
  cout<<head->num<<endl;
return 0;
}