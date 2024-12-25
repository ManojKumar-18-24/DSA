#include<iostream>
using namespace std;

class node
{
    public:
 int data;
 node* next;
 node(int n)
 {
    data=n;
    next=NULL;
 }
};

class dnode
{
    public:
    int num;
    dnode* right;
    dnode* left;
   dnode(int n)
   {
    num=n;
    right=NULL;
    left=NULL;
   }
};

class mnode
{
    public:
    int num;
    node* down;
    mnode* next;
    mnode(int n)
    {
        num=n;
        down=NULL;
        next=NULL;
    }
};

void addmtom(mnode* head,int n)
{
  while(head->next!=NULL)head=head->next;
  mnode* g=new mnode(n);
  head->next=g;
}

void addnodetom(mnode* head)
{
  while(head->next!=NULL)head=head->next;
  int n;cin>>n;
  node* g=new node(n);
  head->down=g;
  node * temp=g;
  while(n!=-1)
  { 
    cin>>n;
    node* g=new node(n);
    temp->next=g;
    temp=temp->next;
    cin>>n;
  }
}

void addendtod(dnode* D,int n)
{
  while(D->right!=NULL)
  {
   D=D->right;
  }
  dnode* g=new dnode(n);
  D->right=g;
  g->left=D;
}

void addfront(dnode* &D,int n)
{
  dnode* g=new dnode(n);
  g->right=D;
  D->left=g;
  g->left=D;
  D=g;
}

int deletefront(dnode* &D)
{
   if(D->right==NULL)
     {
        D=NULL;
        return -1;
      }
      int n=D->num;
   D=D->right;
   D->left->right=NULL;
   D->left=NULL;
   return n;
}

void print(dnode* D)
{
  while(D->right!=NULL)
  {
    cout<<D->num<<" ";
    D=D->right;
  }
  cout<<endl;
}

void print(mnode* head)
{
 while(head!=NULL)
 {
    cout<<head->num<<" ";
    node* temp=head->down;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=head->next;
 }
}

int main()
{

    int n;
    cin>>n;
    mnode* head=new mnode(n);
   while(1) {   cin>>n;   if(n==1)   {      addnodetom(head);   }   cin>>n;   if(n==-2)break;   addmtom(head,n); }
   dnode* D=new dnode(-1);
   addfront(D,head->num);
   while(head!=NULL)
   {
      node* temp=head->down;
      while(temp!=NULL)
      {
        int n=temp->data;
        while(1)
        {
            int m=deletefront(D);
            if(m==-1)
            {
                addendtod(D,n);
                addendtod(D,-1);
                break;
            }
            else if(m<n){addendtod(D,m);}
            else
            {
                addendtod(D,n);
                addendtod(D,m);
                int m=deletefront(D);
                while(m!=-1)
                {
                    addendtod(D,m);
                    m=deletefront(D);
                }
                addendtod(D,-1);
                break;
            }
        }
        temp=temp->next;
      }
      head=head->next;
      if(head==NULL)break;
      int n=head->num;
        while(1)
        {
            int m=deletefront(D);
            if(m==-1)
            {
                addendtod(D,n);
                addendtod(D,-1);
                break;
            }
            else if(m<n){addendtod(D,m);}
            else
            {
                addendtod(D,n);
                addendtod(D,m);
                int m=deletefront(D);
                while(m!=-1)
                {
                    addendtod(D,m);
                    m=deletefront(D);
                }
                addendtod(D,-1);
                break;
            }
        }
   }
    print(D);
  return 0;
}