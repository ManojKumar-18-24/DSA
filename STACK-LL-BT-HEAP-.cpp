#include<bits/stdc++.h>
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

class tree
{
  public:
  int data;
  tree* lc;
  tree* rc;
  tree(int n)
  {
    lc=NULL;
    rc=NULL;
    data=n;
  }
};

void push(node* S)
{
    int n;cin>>n;
    if(n==-1)return;
    S->next=new node(n);
    push(S->next);
}

int pop(node* &S)
{
    if(!S)return -1;
    int n=S->data;
    S=S->next;
    return n;
}

void createbinarytree(tree* &t,node* &S)
{
    int n=pop(S);
    if(n!=0)
    {
        t=new tree(n);
        createbinarytree(t->lc,S);
        createbinarytree(t->rc,S);
    }
}

void Makeheap(vector<int> &heap,int child)
{
      int parent=(child-1)/2;
      if(parent>=0 && heap[parent]>heap[child])
      {
        swap(heap[parent],heap[child]);
        Makeheap(heap,parent);
      }
}

void printandcreateheap(tree* t,vector<int> &heap)
{
    static int i=0;
    if(t)
    {
        printandcreateheap(t->lc,heap);
        cout<<t->data<<" ";
        heap[i]=t->data;i++;
        Makeheap(heap,i-1);
        printandcreateheap(t->rc,heap);
    }
}

void Setheap(vector<int> &heap,int parent=0)
{
   int lc=2*parent+1;
   int rc=2*parent+2;
   if(heap[lc]==-1 && heap[rc]==-1);
   else if(heap[rc]==-1)
   {
      heap[parent]=heap[lc];
      heap[lc]=-1;
      Setheap(heap,lc);
   }
   else if(heap[lc]==-1)
   {
      heap[parent]=heap[rc];
      heap[rc]=-1;
    Setheap(heap,rc);
   }
   else if(heap[lc]<heap[rc])
   {
      heap[parent]=heap[lc];
      heap[lc]=-1;
      Setheap(heap,lc);    
   }
   else
   {
      heap[parent]=heap[rc];
      heap[rc]=-1;
    Setheap(heap,rc);    
   }
}

void print(vector<int> heap)
{
    for(int i=0;i<23;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;  
}

void create(tree* &t,vector<int> a,int high,int low=0)
{
  int n;
  n=(high+low)/2;
  t=new tree(a[n]);
  if(n-1>=low)create(t->lc,a,n-1,low);
  if(n+1<=high) create(t->rc,a,high,n+1);
}

void levelorder(tree* t)
{
    queue<tree*> Q;
    Q.push(t);
    int product=2;int c=0,p=0;
 while(true)
 {
    tree* t=Q.front();Q.pop();
    if(t==NULL){Q.push(t);Q.push(t);c+=2;}
    else
    {
      cout<<t->data<<" ";
      Q.push(t->lc);Q.push(t->rc);c+=2;p++;
    }
    if(c==product){product*=2;c=0;cout<<9999<<" ";if(p==0)break;p=0;}
 }
}

int main()
{
    int n;
    cin>>n;
    node* S=new node(n);
    push(S);
    tree* t;
    createbinarytree(t,S);
    vector<int> heap(35,-1);
    printandcreateheap(t,heap);
    cout<<endl;
    print(heap);
    vector<int> sorted(20,-1);
    int i=0;
    while(true) {       sorted[i]=heap[0];        if(heap[1]==-1 && heap[2]==-1)break;        i++;         Setheap(heap); }
    cout<<endl;
    for(int i=0;i<sorted.size();i++) {  if(sorted[i]!=-1)cout<<sorted[i]<<" ";}   
     t=NULL;
    create(t,sorted,10);
    cout<<t->data<<endl;
    levelorder(t);
return 0;
}