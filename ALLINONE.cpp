                    // STACK:
                     
/*
#include<bits/stdc++.h>
using namespace std;

struct stack
{
  int size;
  int elements[100];
  int top;
};

int peep(stack &M)
{
   return (M.top==-1)?-1:M.elements[M.top];
}

int pop(stack &M)
{
    return ( M.top==-1)?-1: M.elements[M.top--];
}
template <class T>
void push(stack &M,T x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

                // QUEUE:

struct queue
{
 int size=50,front=-1,rear=-1,elements[50];
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

void enq(queue& Q,int x)
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

int deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 {
  int n=Q.elements[Q.front];
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

                 // DEQUE:
                  
struct queue
{
    int size=50,front=50,rear=-1,elements[50];
};

int isq_full(queue Q)
{
   if(Q.rear+1==Q.front)return true;
   return false;
}

void enqf(queue &Q,int x)
{
  if(isq_full(Q))
  {
    cout<<"its full ";
  }
  else
  {
     if(Q.front==0)Q.front=Q.size;
     Q.front--;
     Q.elements[Q.front]=x;
  }
}

void enqr(queue& Q,int x)
{
   if(isq_full(Q))
  {
    cout<<"its full";
  }
  else
  {
     if(Q.rear==Q.size-1)Q.rear=-1;
     Q.rear++;
     Q.elements[Q.rear]=x;
  }   
}

int deqf(queue& Q)
{
  if(Q.front==Q.size)
  {
    cout<<"empty";
  }
  else
  {
    int n=Q.elements[Q.front];
    Q.front++;
    return n;
  }
}

int deqr(queue &Q)
{
   if(Q.rear==-1)
  {
    cout<<"empty";
  }
  else
  {
    int n=Q.elements[Q.rear];
    Q.rear--;
    return n;
  }
}

                //  LINKED std::list
                  

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

               DLL :
             
#include<iostream>
using namespace std;

class dnode
{
  public:
  dnode* left;
  int data;
  dnode* right;
  dnode(int m)
    {
     left=NULL;
     right=NULL;
     data=m;
    }
};

void print(dnode* D)
{
  while(D!=NULL)
  {
    cout<<D->data<<" ";
    D=D->right;
  }
  cout<<endl;
}

void addfront(dnode* &D,int n)
{
  dnode* g=new dnode(n);
  g->right=D;
  D->left=g;
  g->left=D;
  D=g;
}

void addend(dnode* D,int n)
{
  while(D->right!=NULL)
  {
   D=D->right;
  }
  dnode* g=new dnode(n);
  D->right=g;
  g->left=D;
}

void addbefore(dnode* &D,int x,int y)
{
  dnode* temp=D;
  if(temp->data==y)
  {
    dnode* g=new dnode(x);
    D->left=g;
    g->right=D;
    D=g;
    return;
  }
  while((temp->right)->data!=y)
  {
    temp=temp->right;
  }
  dnode* g=new dnode(x);
  temp->right->left=g;
  g->right=temp->right;
  temp->right=g;
  g->left=temp;
}

void addafter(dnode* D,int x,int y)
{
  dnode* temp=D;
  dnode* g=new dnode(x);
  if(temp->data==y)
  {
     D->right->left=g;
     g->right=D->right;
     D->right=g;
     g->left=D;
    return;
  }
  while(temp->data!=y)
  {
    temp=temp->right;
  }
  if(temp->right==NULL)
  {
    temp->right=g;
    g->left=temp;
    return;
  }
  temp->right->left=g;
  g->right=temp->right;
  temp->right=g;
  g->left=temp;
}

void deletefront(dnode* &D)
{
   if(D->right==NULL)
     {
        D=NULL;
        return;
      }
   D=D->right;
   D->left->right=NULL;
   D->left=NULL;
}

void deleteend(dnode* D)
{
  if(D->right==NULL)
     {
        D=NULL;
        return;
      }
  while(D->right->right!=NULL)
  {
     D=D->right;
  }
  D->right->left=NULL;
  D->right=NULL;
}

void deletespecific(dnode* &D,int k)
{
  if(D->data==k)
  {
   deletefront(D);
   return;
  }
  dnode* temp=D;
   while((temp->right)->data!=k)
    {
      temp=temp->right;
    }
    if(temp->right->right==NULL)
    {
        deleteend(D);
        return;
    }
    temp->right->left==NULL;
    temp->right->right->left=temp;
    temp->right= temp->right->right;
}
                  
                //  MULTILEVEL LL 
                  
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

class M
{
  public:
  int data;
  node* down;
  M* next;
  M(int n)
  {
    data=n;
    down=NULL;
    next=NULL;
  }
};

M* addend(M* head,int n)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    M* g=new M(n);
    head->next=g;
   return g;
}

void addendnode(M* tail,int n)
{
    node* temp=tail->down;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node * g=new node(n);
    temp->next=g;
}

void print(M* head)
{
 while(head!=NULL)
 {
    cout<<head->data<<" ";
    node* temp=head->down;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=head->next;
 }
}

                    //  BST:
                      
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

void create(tree* &t,int k)
{
   if(t==NULL)
   {
    t=new tree(k);
   }
   else if(t->data>k)
   {
     create(t->lc,k);
   }
   else 
   {
    create(t->rc,k);
   }
}

              //  BT:
                
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

                //  GT:
                  
class tree
{
    public:
    tree* fc;
    char data;
    tree* ns;
    tree(char n)
    {
        fc=NULL;
        data=n;
        ns=NULL;
    }
};

void create(tree* &t)
{
  char ch;cin>>ch;
  if(ch!='.')
  {
    t=new tree(ch);
    create(t->fc);
    create(t->ns);
  }
}

              //  TRIE:
                
class trienode
{
  public:
  trienode* ptr[26];
  int eow;
  trienode()
  {
    eow=0;
    for(int i=0;i<26;i++)ptr[i]=NULL;
  }
};

void add(trienode* &t,string s,int i=0)
{
   if(t==NULL)
   {
    t=new trienode;
   }
    if(i==s.length())t->eow=1;
    else
    {
        add(t->ptr[s[i]-'a'],s,i+1);
    }
}

                    //  M-WAY TREE:
                
class mtree
{  
    public:
    int count=0;
   vector<int> keys={-1};
   vector<mtree*> ptr;
   mtree(int m,int n)
   {
    keys.resize(m-1);
    for(int i=0;i<keys.size();i++)keys[i]=-1;
    keys[0]=n;
    count++;
    ptr.resize(m);
   }
};

void Add(mtree* &head,int m,int key)
{
  if(!head)
  {
    head=new mtree(m,key);
  }
  else
  {
    if(head->count<m-1)
    {
      for(int i=0;i<head->keys.size();i++)
      {
        if(key<head->keys[i] || head->keys[i]==-1)
        {
           for(int j=head->keys.size()-1;j>i;j--)
           {
             head->keys[j]=head->keys[j-1];
           }
           head->keys[i]=key;
           head->count++;
           return;
        }
      }
    }
    else
    {
           for(int j=0;j<head->keys.size();j++)
           {
             if(key<head->keys[j]){Add(head->ptr[j],m,key);return;}
           } 
           if(key>head->keys[m-2]) Add(head->ptr[m-1],m,key);    
    }
  }
}

                // HOFFMAN:
                 
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct two
{
   int frequency;
   char letter;
};

class tree
{
    public:
    tree* lc;
    two data;
    tree* rc;
    tree(two req)
    {
        lc=NULL;
        data.frequency=req.frequency;
        data.letter=req.letter;
        rc=NULL;
    }
};

vector<tree*> nodecreator(vector<tree*> &h)
{
    vector<tree*> v;
    int i=0;
    for(int i=1;i<=2;i++)
    {
        for(int j=h.size()-1;j>0;j--)
        {
            if(h[j]->data.frequency<h[j-1]->data.frequency)
            {
                swap(h[j],h[j-1]);
            }
        }
    }
    two req;
    req.letter='#';
    req.frequency=h[0]->data.frequency+h[1]->data.frequency;
    tree* g=new tree(req);
    g->lc=h[0];g->rc=h[1];
    for(int i=2;i<h.size();i++)
    {
        v.push_back(h[i]);
    }
    v.push_back(g);
    return v;
}

void print(tree* t,map<char,string> &m,string s="")
{
    if(t!=NULL)
    {
       if(t->data.letter!='#')
       {
         m[t->data.letter]=s;
       }
       print(t->lc,m,s+'0');
       print(t->rc,m,s+'1');
    }
}

void decode(tree* t,string s,int &i)
{
    if(t)
    {
       if(t->data.letter!='#')
       {
         cout<<t->data.letter;
       }  
       else
       {
           if(s[i]=='0')
           {
              i++; decode(t->lc,s,i);
           }
           else
           {
               i++;decode(t->rc,s,i);
           }
       }
    }
}

int main()
{
    vector<two> v;
    vector<tree*> storer;
    two req;
    cin>>req.letter>>req.frequency;
    while(req.frequency!=-1 && req.letter!='#')
    {
        v.push_back(req);
        cin>>req.letter>>req.frequency;
    }
    int i=0;
    while(i<v.size())
    {
        tree* g=new tree(v[i]);
        storer.push_back(g);
        i++;
    }
    while(1)
    {
        storer=nodecreator(storer);
        if(storer.size()==1)break;
    }
    map<char,string> m;
    print(storer[0],m);
    string input,output;
    cin>>input;
    for(int i=0;i<input.length()-1;i++)
    {
        for(auto it=m.begin();it!=m.end();++it)
        {
            if((*it).first==input[i])
            {
                output+=(*it).second;
            }
        }
    }
    cout<<output<<endl;
    cin>>input;
     i=0;
    while(i<input.length()-1)
    {
        decode(storer[0],input,i);
    }
    return 0;
}

            //  HEAPS:
              
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

              //  SEGMENT TREE:
                
int BuildST(vector<int> &ST,int i,vector<int> A,int l,int r)
{
     if(l==r)
     {
        ST[i]=A[l];
     }
     else
     {
       int mid=(l+r)/2;
       ST[i]=BuildST(ST,2*i+1,A,l,mid)+BuildST(ST,2*i+2,A,mid+1,r);
     }
     return ST[i];
}

int GetSum(vector<int> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i];
    if(sr<l || sl>r)
    {
        return 0;
    }
    else
    {
        int mid=(sl+sr)/2;
        return(GetSum(ST,2*i+1,sl,mid,l,r)+GetSum(ST,2*i+2,mid+1,sr,l,r));
    }
    return 0;
}

void Update(vector<int>&ST,int i,int sl,int sr,int position,int diff)
{
    if(sl<=position && position<=sr)ST[i]+=diff;
    if(sl==sr)
    {
        ;
    }
    else
    {
        int mid=(sl+sr)/2;
       Update(ST,2*i+1,sl,mid,position,diff);
       Update(ST,2*i+2,mid+1,sr,position,diff);

    }
} 

                 //  DJSHUDRA:
                   
int FindMin(int Visited[11],int Distance[11])
{
    int c=0,min=10000,j,i=0;
     for(i=0;i<11;i++)
     {
        if(Visited[i]==0)
        {
            c=1;
            if(Distance[i]<min)
            {
              min=Distance[i];j=i;
            }
        }
     }
    if(c==0)return -1;
    return j;
}

void FindShortestPath(int G[11][11],string S[11][11],int Distance[11],int store[11],int Visited[11],int Source)
{
  for(int i=0;i<11;i++){  if(Visited[i]==0 && G[Source][i]!=0 && G[Source][i]+Distance[Source]<Distance[i])  { Distance[i]=G[Source][i]+Distance[Source]; store[i]=Source;}}
  Visited[Source]=1;
  int k=FindMin(Visited,Distance);
  if(k+1)
  {
    FindShortestPath(G,S,Distance,store,Visited,k);
  }
}

              //   KRUSKAL:
                 
struct three
{
   int v1;
   int v2;
   int cost;
};

three FindMin(int G[8][8])
{
  three req;
  req.cost=999;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(G[i][j]>0 && G[i][j]<req.cost)
      {
         req.cost=G[i][j];
         req.v1=i;
         req.v2=j;
      }
    }
  }
  return req;
}

int Find(int A[8],int i)
{
  if(A[i]==i)return i;
  return Find(A,A[i]);
}

int  KRUSKALSMAGIC(int G[8][8],int A[8])
{
  three req=FindMin(G);
  if(req.cost==999)return 0;
  G[req.v1][req.v2]=-1;
  cout<<req.v1<<" "<<req.v2<<endl;
  if(Find(A,req.v1)!=Find(A,req.v2))
  {
    cout<<req.v1<<" "<<req.v2<<" "<<1<<endl;
    A[req.v1]=Find(A,req.v2);
    return(req.cost+KRUSKALSMAGIC(G,A));
  }
  cout<<req.v1<<" "<<req.v2<<" "<<0<<endl;
  return KRUSKALSMAGIC(G,A);
}
*/