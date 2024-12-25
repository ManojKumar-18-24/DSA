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

class Snode
{
    public:
    node* ptr1;
    node* ptr2;
    Snode* next;
    Snode()
    {   ptr1=NULL;
        ptr2=NULL;
        next=NULL;
    }
};

void addend(node* L,int n)
{
     while(L->next!=NULL)
     {
         L= L->next;
     }
     node* g=new node(n);
     L->next=g;
}

void addend(Snode* L)
{
     while(L->next!=NULL)
     {
         L= L->next;
     }
     Snode* g=new Snode;
    L->next=g;
}

void printing(Snode* SL)
{ 
    while(SL->next)
    {
        while(((SL)->ptr1)->data <((SL)->ptr2)->data)
        {
            cout<<((SL)->ptr1)->data<<" ";
            node* temp=(SL)->ptr1;
            (SL)->ptr1=temp->next;
        }
        Snode* temp=SL;
        temp=temp->next;
        while(((SL)->ptr2)->data <((temp)->ptr1)->data)
        {
            cout<<((SL)->ptr2)->data<<" ";
            node* temp=(SL)->ptr2;
            (SL)->ptr2=temp->next;
        }
        SL=temp;
    }
    while(((SL)->ptr1)->data <((SL)->ptr2)->data)
        {
            cout<<((SL)->ptr1)->data<<" ";
            node* temp=(SL)->ptr1;
            (SL)->ptr1=temp->next;
           if(((SL)->ptr1)==NULL)break;
        }
        node* temp=SL->ptr2;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}

void link(node* L1,node* L2,Snode * SL)
{
    Snode * temp;
    temp=SL;
    int t=0;
   while(1)
   {  
       while(L1->data<L2->data)
       {
          if(t==0){temp->ptr1=L1;t++;}
          L1=L1->next;
          if(!L1) 
           break;
       } if(!L1)break;;
       t=0;
       while(L2->data<L1->data)
       {
          if(t==0){temp->ptr2=L2;t++;}
          L2=L2->next;
          if(!L2)
          break;
       }
       if(!L2)break;
        t=0;
        addend(temp);
        temp=temp->next;
   }
   if(!L1)
   {
    temp->ptr2=L2;
   } 
}

int main()
{
    int n;cin>>n;
    node* L1=new node(n);cin>>n;
    while(n!=-1){    addend(L1,n);cin>>n;}
    cin>>n;
    node* L2=new node(n);cin>>n;
    while(n!=-1)  {      addend(L2,n);cin>>n;  }
    Snode * SL;
    SL=new Snode;
    link(L1,L2,SL);
    printing(SL);
    return 0;
}