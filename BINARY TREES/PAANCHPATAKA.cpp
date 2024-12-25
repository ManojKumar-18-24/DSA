#include<iostream>
#include<queue>
using namespace std;

class tree
{
    public:
    tree* lc;
    char data;
    tree* rc;
    tree* p;
    tree* ls;
    tree* rs;
    tree(char n)
    {
        lc=NULL;
        data=n;
        rc=NULL;
        p=NULL;
        ls=NULL;
        rs=NULL;
    }
};

void createbtree(tree* &t)
{
    char ch;cin>>ch;
    if(ch!='#')
    {
        t=new tree(ch);
        createbtree(t->lc);
        createbtree(t->rc);
    }
}

void Attach5Ptrs(queue<tree*> Q)
{
    tree* prevnode=NULL;
    tree* nextnode=NULL;
    int count=0,product=1,p=0;
    while(!Q.empty())
    {
        tree* t=Q.front();
        Q.pop();  count++;
        if(t==NULL)
        {
            Q.push(NULL);
            Q.push(NULL);
        }
       else
       {
        cout<<t->data<<" ";
         t->ls=prevnode;
         if(prevnode!=NULL)
         {
            prevnode->rs=t;
         }
        p++;
        prevnode=t;
        if(t->rc!=NULL)
        {
            t->rc->p=t;
        }
          Q.push(t->rc);
        if(t->lc!=NULL)
        {
            t->lc->p=t;
        } 
        Q.push(t->lc);
       }
      if(count==product)
      {
        count=0;
        product*=2;
        if(p==0)break;
        p=0;
        prevnode=NULL;
      }
    }
}

void print(tree* t,char ch)
{
 if(t!=NULL)
 {
  if(t->data==ch)
  {
    if(t->p!=NULL)cout<<t->p->data<<endl;
    if(t->p->p!=NULL)cout<<t->p->p->data<<endl;
    tree* temp=t->ls;
    while(temp)
    {
      cout<<temp->data;temp=temp->ls;
    }
    if(t->lc!=NULL)cout<<t->lc->data<<endl;
    if(t->rc!=NULL)cout<<t->rc->data<<endl; 
    temp=t->rs;
    while(temp)
    {
     cout<<temp->data;temp=temp->rs;
    }
  }
  else
  {
     print(t->lc,ch);
     print(t->rc,ch);
  }
 }
}

int main()
{
    tree* t;
    createbtree(t);
    queue<tree*> Q;
    Q.push(t);
    Attach5Ptrs(Q);
    char ch;
    cin>>ch;
    print(t,ch);
    return 0;
}