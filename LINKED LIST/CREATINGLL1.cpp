#include<iostream>
using namespace std;

class node
{  
  public:
  int num;
  node* ptr;
  node(int num1)
  {  cout<<"called"<<endl;
    num=num1;
    ptr=NULL;
  }
};

void printing( node* &head)
{
  while(head!=NULL)
  {
  cout<<head -> num<<" ";
  head=head ->ptr;
  }
}

void insertathead(node* &head)
{
   node* g=new node(4);
   g ->ptr=head;
   head=g;
}

void insertattail(node* &head)
{
  node* g=new node(9);
  head->ptr=g;

}

void insertatmiddle(int pos,node* &head)
{
   
}

int main()
{
  node* head=new node(3); 
  insertattail(head);
  printing(head);
 return 0;
}