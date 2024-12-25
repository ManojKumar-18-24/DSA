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

int check=1;

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
    }
}

node*  read()
{
  int n;cin>>n;
  node* head=new node(n);
  cin>>n;
  while(n!=-1)
  {
    addend(head,n);
    cin>>n;
  }
  return head;
}

void palcheck(node* head)
{
 static node* SP=head;
 static node* FP=head;
 if(FP==NULL || FP->next==NULL)
 {
    if( FP!=NULL && FP->next==NULL)SP=SP->next;
 }
 else
 {
    int n=SP->num;
    SP=SP->next;FP=FP->next->next;
    palcheck(head);
     if(n!=SP->num)check=0;
     SP=SP->next;
 }
}

void removedups(node* head)
{
  static node* temp=head;
  static node* prev=head;
  if(head==NULL);
  else
  {
    int n=head->num,flag=0;
    node* f=temp;
    if(head!=temp && head!=temp->next)prev=prev->next;
    node* s=prev;
    if(head->next!=NULL && head->next->num==n)flag++;
    removedups(head->next);
    if(flag>0)
    {
        s->next=s->next->next;
        head->next=NULL;
    }
  }
}

void removedupus(node* head)
{
  static node* temp=head;
  static node* prev=head;
  if(head==NULL);
  else
  {
    int n=head->num,flag=0;
    node* f=temp;
    if(head!=temp && head!=temp->next)prev=prev->next;
    node* s=prev;
    while(f!=head)
    {
        if(f->num==n){flag++;break;}f=f->next;
    }
    removedupus(head->next);
    if(flag>0)
    {
        s->next=s->next->next;
        head->next=NULL;
    }
  }
}

void removelast(node* head)
{
  static node* temp=head;
  static node* prev=head;
  if(head==NULL);
  else
  {
    int n=head->num,flag=0;
    node* f=temp;
    if(head!=temp && head!=temp->next)prev=prev->next;
    node* s=prev;
    while(f!=head)
    {
        if(f->num==n){flag++;break;}f=f->next;
    }
    f=head->next;
    while(f!=NULL)
    {
      if(f->num==n){flag--;break;}f=f->next;
    }
    removelast(head->next);
    if(flag>0)
    {
        s->next=s->next->next;
        head->next=NULL;
    }
  }
}

void segregateoddeven(node* &head)
{
  static int c=0;
  static node* temp=head;
  static node* prev=head;
  if(head->num==-1){;}
  else
  {
    if(c==0 && head!=temp && head!=temp->next) prev=prev->next;
    //node* s=prev;
    int n=head->num;
    head=head->next;
    if((n)%2!=0)
    { 
      c=1;
      node* temp2=temp;
      while(temp->next!=NULL)temp=temp->next;
      temp->next=prev->next;
      temp->next->next=NULL;
      prev->next=prev->next->next;
    }
    else c=0;
      segregateoddeven(head);
  }
}

int main()
{
  //   palcheck(read());
  //   cout<<check<<endl;
  //   node* temp=read();
  //   removedups(temp);
  //   printing(temp);
  //   temp=read();
  //   removedupus(temp);
  //   printing(temp);
  //   temp=read();
  //  removelast(temp);
  //  printing(temp);
   node* temp=read();addend(temp,-1);
  segregateoddeven(temp);
   printing(temp);
    return 0;
}