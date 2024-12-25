#include<iostream>
#include<stack>
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

void create(tree* &t)
{
    int n;
    cin>>n;
    if(n!=0)
    {
        t=new tree(n);
        create(t->lc);
        create(t->rc);
    }
}

int main()
{
  tree* t1;
  tree* t2;
  create(t1);
  create(t2);
  stack<tree*> s1;
  stack<tree*> s2;
  s1.push(t1);
  s2.push(t2);
  tree* temp1=t1->lc;
  tree* temp2=t2->lc;
  int c=0,d=0;
  while(true)
  {
    if(c==0)
    {
        while(temp1)
         {
        cout<<temp1->data<<endl;           
            s1.push(temp1);
            temp1=temp1->lc;
         }
        temp1=s1.top();s1.pop();
        cout<<temp1->data<<endl;
        if(!temp1->rc && !temp1->lc)
        {
            c=temp1->data;
            while(!s1.empty())
            {
             temp1=s1.top();s1.pop();
             if(temp1->rc!=NULL)
             {
                 temp1=temp1->rc;break;
             }
            }
        }
        else temp1=temp1->rc;
    }
    if(d==0)
    {  while(temp2)
        {
        cout<<temp2->data<<endl;
           s2.push(temp2);
           temp2=temp2->lc;
        }
        temp2=s2.top();s2.pop();
         cout<<temp2->data<<endl;
        if(!temp2->rc && !temp2->lc)
        {
            d=temp2->data;
            while(!s2.empty())
            {
             temp2=s2.top();s2.pop();
             if(temp2->rc!=NULL)
             {
                 temp2=temp2->rc;break;
             }
            }            
        }
        else temp2=temp2->rc; 
    }
    if(d && c)
    {
        cout<<c<<" "<<d<<endl;
        c=0;d=0;
    }
  }
  return 0;
}