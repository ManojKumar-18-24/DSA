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

void reverse(node* &head,int left,int right)
{
  
}

int main()
{
  int p,left,right;cin>>p;
  node* head=new node(p);cin>>p;
  while(p!=-1)
  {
    addend(head,p);
    cin>>p;
  }
  cin>>left>>right;
  
return 0;
}