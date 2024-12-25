#include<iostream>
using namespace std;

class node
{  
  public:
  int num;
  int expo;
  node* ptr;
  node(int num1,int p)
  {  
    num=num1;
    expo=p;
    ptr=NULL;
  }
};

void printing( node* &head)
{
  while(head!=NULL)
  {
  cout<<head -> num<<" "<<head->expo<<" ";
  head=head ->ptr;
  }
  cout<<endl;
}

void insertattail(node* &tail,int n,int p)
{
  node* g=new node(n,p);
  tail->ptr=g;
  tail=g;
}

void expoprint(node* head1,node*head2)
{

  while(head1 && head2)
  {
    if(head1->expo > head2->expo)
    {
        cout<<head1->num<<" "<<head1->expo<<" ";
        head1=head1->ptr;
    }
    else if(head1->expo < head2->expo)
    {
        cout<<head2->num<<" "<<head2->expo<<" ";
        head2=head2->ptr;      
    }
    else
    {
        cout<<head1->num+head2->num<<" "<<head1->expo<<" ";
        head1=head1->ptr;
        head2=head2->ptr; 
    }
  }
  while(head2)
  {
    cout<<head2->num<<" "<<head2->expo<<" ";
    head2=head2->ptr;
  }
  while(head1)
  {
    cout<<head1->num<<" "<<head1->expo<<" ";
    head1=head1->ptr;
  } 
}

int main()
{
  int n,p;
  cin>>n>>p;
  node* head1=new node(n,p);
  node* tail1=head1;
  cin>>n>>p;
  while(n!=-1)
  {    
      insertattail(tail1,n,p);
      cin>>n ;if(n!=-1)cin>>p;
  }
  cin>>n>>p;
  node* head2=new node(n,p);
  node* tail2=head2;
  cin>>n>>p;
  while(n!=-1)
  {
      insertattail(tail2,n,p);
      cin>>n ;if(n!=-1)cin>>p;
  }
  expoprint(head1,head2);
 return 0;
}
