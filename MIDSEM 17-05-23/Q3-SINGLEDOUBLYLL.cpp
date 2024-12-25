#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next=NULL;
    node(int m)
    {
        data=m;
    }
};

class dnode
{
    public:
    int data;
    dnode* left=NULL;
    dnode* right=NULL;
    dnode(int m)
    {
        data=m;
    }
};

void addend(node* temp,int x)
{
  while(temp->next!=NULL)temp=temp->next;
  node* g=new node(x);
  temp->next=g;
}

void addend(dnode* &D,int x)
{
  if(D==NULL)
  {
    D=new dnode(x);return;
  }
  dnode* temp=D;
  while(temp->right!=NULL)
  {
   temp=temp->right;
  }
  dnode* g=new dnode(x);
  temp->right=g;
  g->left=temp;
}

void deletenode(node* &head,int key)
{
 if(head->data==key)
 {
    head=head->next;
    return;
 }
 node* temp=head;
 while(temp->next->data!=key)temp=temp->next;
 temp->next=temp->next->next;
}

node* find(node* temp,int p)
{
 if(p==0)
 {
    while(temp && temp->data%2!=0)temp=temp->next;
 }
 else
 {
    while(temp && temp->data%2==0)temp=temp->next; 
 }
 return temp;
}

int main()
{
 int n;cin>>n;
 node* head1=new node(n);
 cin>>n;
 while(n!=-1){   addend(head1,n);cin>>n;}
cin>>n;
 node* head2=new node(n);
 cin>>n;
 while(n!=-1){   addend(head2,n);cin>>n;} 
 dnode* D=NULL;
 node* g=find(head1,0);
 node* f=find(head2,0);
 while(1)
 {
    if(g==NULL)
    {
       while(f!=NULL)
       {
         addend(D,f->data);
         deletenode(head2,f->data);
         f=find(head2,0);
       }
       break;
    }
    if(f==NULL)
    {
       while(g!=NULL)
       {
         addend(D,g->data);
         deletenode(head1,g->data);
         g=find(head1,0);
       }
       break;
    } 
    if(g->data>f->data)
    {
         addend(D,f->data);
         deletenode(head2,f->data);
         f=find(head2,0);       
    }  
    else
    {
         addend(D,g->data);
         deletenode(head1,g->data);
         g=find(head1,0);       
    } 
 }
  g=find(head1,1);
  f=find(head2,1);
 while(1)
 {
    if(g==NULL)
    {
       while(f!=NULL)
       {
         addend(D,f->data);
         deletenode(head2,f->data);
         f=find(head2,1);
       }
       break;
    }
    if(f==NULL)
    {
       while(g!=NULL)
       {
         addend(D,g->data);
         deletenode(head1,g->data);
         g=find(head1,1);
       }
       break;
    } 
    if(g->data>f->data)
    {
         addend(D,f->data);
         deletenode(head2,f->data);
         f=find(head2,1);       
    }  
    else
    {
         addend(D,g->data);
         deletenode(head1,g->data);
         g=find(head1,1);       
    } 
 } 
 cout<<endl;
 while(D)
 {
    cout<<D->data<<" ";
    D=D->right;
 }
return 0;
}