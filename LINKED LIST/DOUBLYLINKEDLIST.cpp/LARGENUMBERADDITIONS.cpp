#include<iostream>
using namespace std;

class dnode
{  
  public:
  int num;
  dnode* left;
  dnode* ptr;
  dnode(int num1)
  { 
    num=num1;
    ptr=NULL;
    left=NULL;
  }
};

int carry=0;

void printing( dnode* head)
{
  while(head->ptr!=NULL)
  {
  cout<<head -> num;
  head=head ->ptr;
  }
  cout<<endl;
}

void addfront(dnode* &D,int n)
{
  dnode* g=new dnode(n);
  g->ptr=D;
  D->left=g;
  g->left=D;
  D=g;
}

void addend(dnode* D,int n)
{
  while(D->ptr!=NULL)
  {
   D=D->ptr;
  }
  dnode* g=new dnode(n);
  D->ptr=g;
  g->left=D;
}

void add(dnode* head1,dnode* head2,dnode* &head3)
{   
   if(head1==NULL)
   {
       ;
   }
   else
   {
       int n=head1->num,m=head2->num;
       add(head1->ptr,head2->ptr,head3);
       int sum=m+n;sum+=carry;carry=sum/10;
       addfront(head3,sum%10);
   }
}

int main()
{
  string n;int p=1,r=1;
  cin>>n;
  dnode* head1=new dnode(n[0]-'0');
  while(n[p]!='#'){  addend(head1,n[p]-'0');  p++;}
  cin>>n;
  dnode* head2=new dnode(n[0]-'0');
  while(n[r]!='#') {   addend(head2,n[r]-'0');   r++; }  
  if(r>p)
  {
      for(int i=1;i<=(r-p);i++){ addfront(head1,0);}
  }
  else
  {
     for(int i=1;i<=(p-r);i++){     addfront(head2,0); }  
  }
  dnode * head3=new dnode(0);
  add(head1,head2,head3);
  if(carry!=0)addfront(head3,carry);
  printing(head3);
 return 0;
}
