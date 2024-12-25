#include<bits/stdc++.h>
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

void insert(node* HM[10],int n)
{
   if(HM[n%10]) addend(HM[n%10],n);
   else
   {
    HM[n%10]=new node(n);
   }
}

void print2(node* temp)
{
    if(temp)
    {
        print2(temp->next);
        cout<<temp->data<<" ";
    }
}

void print1(node* HM[10])
{
 
 for(int i=0;i<10;i++)
 {
    cout<<i<<" ";
    print2(HM[i]);
    cout<<endl;
 }
}

int main()
{
   node* g=new node(-1);
   node* HM[10]={NULL};
   int n;cin>>n;
   while(n!=-1)
   {
    insert(HM,n);cin>>n;
   }
   print1(HM);
return 0;
}