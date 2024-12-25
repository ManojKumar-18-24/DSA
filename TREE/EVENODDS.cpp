#include<iostream>
#include<vector>
using namespace std;

class tree
{
    public:
    tree* fc;
    int data;
    tree* ns;
    tree(int n)
    {
        fc=NULL;
        data=n;
        ns=NULL;
    }
};

int i=0;

struct queue
{
 int size=50,front=-1,rear=-1;tree *elements[50];
};

bool is_qfull(queue Q)
{
  if((Q.rear+1)%Q.size==Q.front)
  return true;
  return false;
}

bool is_qempty(queue Q)
{ 
  if(Q.front==-1 && Q.rear==-1)
  return true;
  return false;
}

void enq(queue& Q,tree* x)
{
    if(is_qfull(Q))
    {
      cout<<"it's full";
    }
    else
    {
     if(Q.front==-1)Q.front++;
     Q.rear=(Q.rear+1)%Q.size;
     Q.elements[Q.rear]=x;
    }
}

tree* deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 {
  tree* n=Q.elements[Q.front];
  if(Q.front==Q.rear)
  {
    Q.front=-1;Q.rear=-1;
  }
  else
  {
    Q.front=(Q.front+1)%Q.size;
  }
  return n;
 }
 return NULL;
}

void create(tree* &t,int a[])
{
  if(a[i]!=0)
  {
    t=new tree(a[i]);i++;
    create(t->fc,a);i++;
    create(t->ns,a);
  }
}

vector<int> Get(tree* t)
{
   queue Q;
   vector<int> v;
  enq(Q,t);enq(Q,NULL);
  while(!is_qempty(Q))
  {
    tree* g=deq(Q);
    if(g!=NULL){v.push_back(g->data);g=g->fc;}
    else
    {
      if(is_qempty(Q))return v;
      enq(Q,NULL);
    }
    while(g)
    {
      enq(Q,g);g=g->ns;
    }
  }
  return v;
}

void Give(tree* t,vector<int> v)
{
   queue Q;int index=0;
  enq(Q,t);
  while(!is_qempty(Q))
  {
    tree* g=deq(Q);
    if(g!=NULL){g->data=v[index];index++;g=g->fc;}
    else
    {
      if(is_qempty(Q))return ;
    }
    while(g)
    {
      enq(Q,g);g=g->ns;
    }
  }
}

void Change(vector<int> &v)
{
  int low=0;
  int high=v.size()-1;
  vector<int> v1;
  while(low<high)
  {
    while(low<v.size() && v[low]%2==0)low++;
    while(high>=0 && v[high]%2!=0)high--;
    if(low<high)
    {v1.push_back(v[low]);
    v[low]=v[high];
    v[high]=-1;
    low++;high--;
    }
  }
  low=0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]==-1)
    {
      v[i]=v1[low];low++;
    }
  }
}

void dftprint(tree* t)
{
  if(t!=NULL)
  {
    cout<<t->data<<" ";
    dftprint(t->fc);
    dftprint(t->ns);
  }
}

int main()
{
    tree* t;
    int a[]={4,1,5,0,6,0,0,3,9,0,0,2,7,8,0,0,0,0,0};
    create(t,a);
    vector<int> c=Get(t);
    Change(c);
    Give(t,c);
    dftprint(t);cout<<endl; tree* g;
    int b[]={1,2,3,4,5,6,7,0,0,8,9,0,0,0,0,10,11,12,0,0,14,15,16,0,0,0,17,18,0,0,0,0,0,0,0};
    i=0;
    create(g,b);
    vector<int> d=Get(g);
     Change(d);
     Give(g,d);
    dftprint(g);
    return 0;
}