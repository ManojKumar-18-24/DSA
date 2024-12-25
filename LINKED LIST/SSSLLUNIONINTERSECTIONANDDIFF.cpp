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
  if(LPTR->next==NULL)
  {
    
  }
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
       if(LPTR->num!=-1) cout<<LPTR->num<<" ";
        LPTR=LPTR->next;
    }cout<<"\n";
}

node* unionofsortedLL(node* L1,node* L2)
{
    node* L3=new node(-1);
 while(L1 && L2)
  {
    if(L1->num<L2->num)
     {
       addend(L3,L1->num);L1=L1->next;
     }
     else if(L1->num>L2->num)
     {
       addend(L3,L2->num);L2=L2->next;
     }
     else
     {
        addend(L3,L1->num);L1=L1->next;L2=L2->next;
     }
  }
 while(L1)
 {
    addend(L3,L1->num);L1=L1->next;
 }
 while(L2)
 {
    addend(L3,L2->num);L2=L2->next;
 }
 return L3;
}

node* intersectionofsortedLL(node* L1,node* L2)
{
    node* L3=new node(-1);
 while(L1 && L2)
  {
    if(L1->num<L2->num)
     {
       L1=L1->next;
     }
     else if(L1->num>L2->num)
     {
       L2=L2->next;
     }
     else
     {
        addend(L3,L1->num);L1=L1->next;L2=L2->next;
     }
  }
 return L3;
}

node* difofsortedLL(node* L1,node* L2)
{
    node* L3=new node(-1);
  while(L1 && L2)
  {
    if(L2->num<L1->num)
     {
       L2=L2->next;
     }
     else if(L1->num==L2->num)
     {
       L1=L1->next;L2=L2->next;
     }
     else
     {
        addend(L3,L1->num);L1=L1->next;
     }
  }
   while(L1)
 {
    addend(L3,L1->num);L1=L1->next;
 }
 return L3;
}

int check(node* L,int n)
{
    while(L)
    {
        if(L->num==n)return 0;
        L=L->next;
    }
    return 1;
}

node* unionofunsortedLL(node* L1,node* L2)
{
   node* L3=new node(-1);
      while(L1)
      {
         addend(L3,L1->num);L1=L1->next;
      } 
      while(L2)
      {
        if(check(L3,L2->num)) addend(L3,L2->num);
        L2=L2->next;
      }
      return L3;
}

node* intersectionofunsortedLL(node* L1,node* L2)
{
   node* L3=new node(-1);
      while(L1)
      {
          node* temp=L2;
          while(temp)
           {
            if(L1->num==temp->num)addend(L3,temp->num);
            temp=temp->next;
           } 
           L1=L1->next;
      } 
    return L3;
}

node* difofunsortedLL(node* L1,node* L2)
{
   node* L3=new node(-1);
      while(L1)
      {
          node* temp=L2;int c=0;
          while(temp)
           {
            if(L1->num==temp->num)c++;
            temp=temp->next;
           }
           if(c==0)addend(L3,L1->num);
           L1=L1->next;
      } 
    return L3;
}

int main()
{
    int n;cin>>n;
    node* L1=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(L1,n);
        cin>>n;
    }
    cin>>n;
    node* L2=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(L2,n);
        cin>>n;
    }
    node * L3=unionofsortedLL(L1,L2);
    printing(L3);
    L3=intersectionofsortedLL(L1,L2);
    printing(L3);
    L3=difofsortedLL(L1, L2);
    printing(L3);
    cin>>n;
     L1=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(L1,n);
        cin>>n;
    }
    cin>>n;
     L2=new node(n);
    cin>>n;
    while(n!=-1)
    {
        addend(L2,n);
        cin>>n;
    }
    L3=unionofunsortedLL(L1,L2);
    printing(L3);
    L3=intersectionofunsortedLL(L1,L2);
    printing(L3);
    L3=difofunsortedLL( L1,L2);
    printing(L3); 
    return 0;   
}