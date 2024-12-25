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

tree* rev;

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

tree* find(tree* t,int k)
{
  if(t==NULL)
  {
    return NULL;
  }
  else if(k>t->data)
  {
    rev=t;
    return find(t->rc,k);
  }
  else if(k<t->data)
  {
    rev=t;
    return find(t->lc,k);
  }
  else
  {
    return t;
  }
}

tree* max(tree *t)
{
   if(t->rc==NULL)
    {
      return t;
    }
    return max(t->rc);
}

void printinorder(tree * t)
{
   if(t==NULL);
   else
   {
    
     printinorder(t->lc); cout<<t->data<<" ";
     printinorder(t->rc);
   }
}

void deletenode(tree* &t,int key)
{
    tree *temp=find(t,key);
    if(temp!=t)
    {  
       if(temp->rc==NULL && temp->lc==NULL)
       {
           if(rev->rc==temp)
           rev->rc=NULL;
           else rev->lc=NULL;
       }
       else if(temp->rc==NULL)
       {
         if(rev->rc==temp)
         {
            rev->rc=temp->lc; 
         }
         else rev->lc=temp->lc;
       }
       else if(temp->lc==NULL)
       {
         if(rev->rc==temp)
         {
            rev->rc=temp->rc; 
         }
         else rev->lc=temp->rc;           
       }
       else
       {
           tree* temp2=max(temp->lc);
           tree* temp3=rev;
          temp2=find(t,temp2->data); 
          if(temp3->rc==temp)temp3->rc=temp2;
          else temp3->lc=temp2;
        if(rev!=temp)  rev->rc=temp2->rc;
    if(temp->rc!=temp2) 
    { temp2->rc=temp->rc;}
     if(temp->lc!=temp2)temp2->lc=temp->lc;   
       } printinorder(t);
           cout<<endl;
    }
    else
    {
       if(temp->rc==NULL && temp->lc==NULL)
       {
           t=NULL;
       }
       else if(temp->rc==NULL)
       {
         if(t->rc==temp)
         {
            t->rc=temp->lc; 
         }
         else t->lc=temp->lc;
       }
       else if(temp->lc==NULL)
       {
         if(t->rc==temp)
         {
            t->rc=temp->rc; 
         }
         else t->lc=temp->rc;           
       }
       else
       {
           tree* temp2=max(temp->lc);
            temp2=find(t,temp2->data);
           temp2->rc=temp->rc;
           rev->rc=temp2->lc;temp2->lc=NULL;temp2->lc=t->lc;
           temp2->rc=t->rc;t=temp2;
       }        
    }
}



int main()
{
  int n;cin>>n;
  tree* t=new tree(n);
  cin>>n;
  while(n!=-1){   create(t,n);cin>>n; };
  rev=t;
  cin>>n;
  while(n!=-1)
  {
      deletenode(t,n);
      cin>>n;
  }
  return 0;
}
