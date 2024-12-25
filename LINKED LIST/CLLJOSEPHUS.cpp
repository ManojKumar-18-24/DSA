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
{
    while(LPTR)
    {
        cout<<LPTR->data<<" ";
        LPTR=LPTR->next;
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

void remove(node* head,int m,int n)
{
    static int  count=0,p=0;
    if(p==n/2)
    {
     ;
    }
    else
    {
        if(head->data!=-1)count++;
        if(count==m){head->data=-1;count=0;p++;}
        remove(head->next,m,n);
    }
}

int main()
{
    int n,m;cin>>n>>m;
    node* head=new node(1);
    for(int i=1;i<n;i++)
    {
        addend(head,i+1);
    }
    link(head);
    remove(head,m,n);
    int count=0;
    while(count!=n)
    {
        if(head->data!=-1)cout<<'A';
        else cout<<'B';
        head=head->next;
        count++;
    }
    return 0;
}
