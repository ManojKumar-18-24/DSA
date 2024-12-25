#include<iostream>
using namespace std;

class node
{  
  public:
  int num;
  node* rp;
  node* next;
  node(int num1)
  {  
    num=num1;
    rp=NULL;
    next=NULL;
  }
};

void printing( node* head)
{
  while(head!=NULL)
  {
  cout<<head -> num<<" "<<(head->rp)->num<<" ";
  head=head ->next;
  }
  cout<<endl;
}

void addend(node* LPTR,int n)
{
  while(LPTR->next!=NULL)
  {
    LPTR=LPTR->next;
  }
  node* L=new node(n);
  LPTR->next=L;
}

void right_min(node* head,node* temp)
{   static int max;
    if(temp==NULL)
    {
       if((head->next)!=NULL)
        {
            head=head->next;
            temp=head->next;
            cout<<head->num<<endl;
            right_min(head,temp);
        }
        else
        {
            node* p=new node(0);
            head->rp=p;
        }
    }
    else
    {
        if(temp==head->next)
        {
            max=temp->num;
            head->rp=temp;
            cout<<max<<endl;
        }
        else if(temp->num>max)
        {
            max=temp->num;
            head->rp=temp;
            cout<<max<<endl; 
        }
        temp=temp->next;
        right_min(head,temp);
    }
}

int main()
{
    int n;
    cin>>n;
    node* head=new node(n);cin>>n;
    while(n!=-1)
    {
       addend(head,n);
       cin>>n;
    }
    right_min(head,head->next);
    printing(head);
    return 0;
}
