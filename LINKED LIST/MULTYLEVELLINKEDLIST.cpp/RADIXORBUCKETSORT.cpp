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

void addend(node* LPTR[],int digit,int n)
{
  while(digit>=10)digit/=10;
  if(LPTR[digit]==NULL)
  {
    node* L=new node(n);
    LPTR[digit]=L;
    return;
  }
  node* temp=LPTR[digit];
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  node* L=new node(n);
  temp->next=L;
}

void printing(node* LPTR)
{
    while(LPTR)
    {
        cout<<LPTR->num<<" ";
        LPTR=LPTR->next;
    } cout<<endl;
}

void takeout(node* R[],int a[])
{   int k=0;
    for(int i=0;i<10;i++)
    {
       if(R[i]!=NULL)
       {
         node* temp=R[i];
         while(temp!=NULL)
         {
            a[k]=temp->num;
            k++;
            temp=temp->next;
         }
       }
    }
}

int main()
{
    int n;cin>>n;
    node* R[10]={NULL};
    int max;
    int a[n];cin>>a[0];max=a[0];
    for(int i=1;i<n;i++){cin>>a[i];if(a[i]>max)max=a[i];}
    int noofdigits=0,product=1;
    while(max>0){noofdigits++;max/=10;}
    while(max<noofdigits)
    {
        for(int i=0;i<n;i++)
        {
          if(a[i]<product)
          {
            addend(R,0,a[i]);
          }
          else addend(R,a[i]%(product*10),a[i]);
        }
        takeout(R,a);
        max++;
        product*=10;
        for(int i=0;i<n;i++)
        {
            R[i]=NULL;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }  
    return 0;
}