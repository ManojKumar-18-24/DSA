#include<iostream>
using namespace std;

class tree
{
    public:
    tree* lc;
    int data;
    tree* rc;
    tree(int n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
    }
};

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
}

void createbtree(tree* &t)
{
    int ch;cin>>ch;
    if(ch!=0)
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

void print(tree* t)
{
   if(t==NULL);
   else
   {
    cout<<t->data<<" ";
    print(t->lc);
    print(t->rc);
   }
}

tree* FindPrevNode(tree* t,char ch,tree* parent)
{
   if(t==NULL)return NULL;
   else if( t->data==ch)
   {
    return parent;
   }
   else
   {
    tree* left=FindPrevNode(t->lc,ch,t);
    tree* right=FindPrevNode(t->rc,ch,t);
    if(left!=NULL)return left;
    return right;
   }
}

tree* FindLeafNode(queue Q)
{
    tree* root=deq(Q);enq(Q,root);
 while(!is_qempty(Q))
 {
     tree* g=deq(Q);
    if(g->lc==NULL && g->rc==NULL)
    {
        tree* parent=FindPrevNode(root,g->data,root);
        if(parent->lc!=NULL)
        {
            if(parent->lc->data==g->data)parent->lc=NULL;
        }
        if(parent->rc!=NULL)
        {
            if(parent->rc->data==g->data)parent->rc=NULL;
        } 
        return g;      
    }
    else
    {
        if(g->lc!=NULL)enq(Q,g->lc);
        if(g->rc!=NULL)enq(Q,g->rc);
    }
 }
 return NULL;
}

tree* FindHalfLeafNode(queue Q)
{
    while(!is_qempty(Q))
    {
        tree* g=deq(Q);
        if((g->lc==NULL && g->rc!=NULL) || (g->rc==NULL && g->lc!=NULL))
        {
            return g;
        }
        else
        {
            if(g->lc!=NULL)enq(Q,g->lc);
            if(g->rc!=NULL)enq(Q,g->rc); 
        }
    }
    return NULL;
}

void ChangeT1T2(queue Q1,queue Q2)
{
    while(1)
    {
        tree* f=FindLeafNode(Q2);
        tree* g=FindHalfLeafNode(Q1);
        if(g==NULL)break;
        else
        {    cout<<f->data<<" ";
             cout<<g->data<<" ";
            if(g->lc==NULL)g->lc=f;
            else g->rc=f;
        }
    }
}

void print(tree* t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        print(t->lc);
        print(t->rc);
    }
}
int main()
{
    queue Q1,Q2;
    tree* t1;
    createbtree(t1);
    tree* t2;
    createbtree(t2);
    enq(Q1,t1);enq(Q2,t2);
    ChangeT1T2(Q1,Q2);
    print(t1);cout<<endl;print(t2);
    return 0;
}
