#include<iostream>
using namespace std;

class tree
{
    public:
    tree* nextright;
    tree* downnode;
    int data;
    tree* up_diagonal;
    tree* down_diagonal;
    tree(int n)
    {
        nextright=NULL;
        data=n;
        downnode=NULL;
        up_diagonal=NULL;
        down_diagonal=NULL; 
    }
};

tree* Find(tree* g,int m)
{
    if(g==NULL)return NULL;
    else if(g->data==m)
    {
        return g;
    }
    else
    {
        tree* u;tree* r;
        u=Find(g->nextright,m);
        r=Find(g->downnode,m);
        if(u!=NULL)return u;
        return r;
    }
    return NULL;
}

void LinkFourWay(tree* &g,int M[3][3],int i=0,int j=0)
{   static tree* temp=g;
    tree* Present=Find(temp,M[i][j]);
    if(Present==NULL)
    {
        g=new tree(M[i][j]);
    }
    else g=Present;
   if(j<2) LinkFourWay(g->nextright,M,i,j+1);
   if(i<2) LinkFourWay(g->downnode,M,i+1,j);
   if(i<2 && j<2) LinkFourWay(g->down_diagonal,M,i+1,j+1);
   if(i>0 && j<2) LinkFourWay(g->up_diagonal,M,i-1,j+1);
}

int main()
{
  int M[3][3]={1,2,3,4,5,6,7,8,9};
  tree* g=new tree(M[0][0]);
  LinkFourWay(g,M);
  int n;cin>>n;
  tree* h=Find(g,n);
  tree* temp=h;
  while(h->nextright!=NULL && temp!=NULL)
  {
    cout<<temp->data<<" ";temp=temp->nextright;
  }cout<<endl;
  temp=h;
  while(h->downnode!=NULL && temp !=NULL)
  {
    cout<<temp->data<<" ";temp=temp->downnode;
  }cout<<endl;
  temp=h;
  while(h->up_diagonal!=NULL &&temp !=NULL)
  {
    cout<<temp->data<<" ";temp=temp->up_diagonal;
  }cout<<endl;
  temp=h;
  while(h->down_diagonal!=NULL && temp!=NULL)
  {
    cout<<temp->data<<" ";temp=temp->down_diagonal;
  }
  return 0;
}