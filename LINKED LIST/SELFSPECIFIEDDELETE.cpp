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
        cout<<LPTR->num<<" ";
        LPTR=LPTR->next;
    } cout<<endl;
}

void deleteLL(node* head,node* & temp)
{ 
  static int count=0;
  static node* p=temp;
  if(head==NULL);
  else
  {
     count++;
     if(count>2)p=p->next;
     node* temp3=p;
    int flag=0;
    node* temp1=temp;
    while(temp1!=NULL)
    {
      if(temp1->num==count){flag++;break;} temp1=temp1->next;
    }
    deleteLL(head->next,temp);
    if(flag==1)
    {
      if(temp!=head)
       {
        temp3->next=head->next;
        head->next=NULL;
       }
       else
       {
        temp=temp->next;
       }
    }
  }
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
  node* temp=head;  
  deleteLL(head,temp);  
  printing(temp);     
    return 0;
}