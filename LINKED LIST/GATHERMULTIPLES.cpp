#include<iostream>
using namespace std;

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

void printing(node* LPTR)
{
    while(LPTR)
    {
        cout<<LPTR->num<<" ";
        LPTR=LPTR->next;
    } cout<<endl;
}

void gather_multiples(node* LPTR)
{
  
   int p=9,n;node* t=LPTR;
   node * LPTR2=LPTR->next;
   while((LPTR->num)%p==0)
   {
      cout<<LPTR->num<<endl; 
      LPTR=LPTR->next;
   }
   while(1)
   {  
       if(!LPTR2)return;
       while((LPTR2->num)%p!=0)
       {  //cout<<LPTR2->num<<endl; 
           LPTR2=LPTR2->next;
          if(LPTR2==NULL)
          {       
                  p+=2;
                // printing(t);
                  if(p>=15)return;
                  break;
          }
       }
       if(!LPTR2)
       {
        LPTR2=LPTR;continue;
       }
       //cout<<"brock"<<endl;
       node* temp=LPTR;n=LPTR->num;LPTR->num=LPTR2->num;
      //cout<<" n= "<<n<<endl;
       while(temp!=LPTR2)
       {
           int m=(temp->next)->num;
          // cout<<" m= "<<m<<endl;
           temp=temp->next;
           temp->num=n;
           n=m;
       }
       LPTR=LPTR->next;   
   while((LPTR->num)%p==0)
   {
       LPTR=LPTR->next;
   } 
   LPTR2=LPTR->next;
   }
}

int main()
{
    int n;cin>>n;
    node* LPTR=new node(n);cin>>n;
    while(n!=-1)
    {
        addend(LPTR,n);
        cin>>n;
    }
    gather_multiples(LPTR);
    printing(LPTR);
    return 0;
}