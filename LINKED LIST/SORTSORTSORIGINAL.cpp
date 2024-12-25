#include<iostream>
#include<utility>
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

void nextmin(node* a[],int m)
{
    int i=0;
    node* temp1=a[i];
    while(1)
    {
        node* temp2=NULL;
       int min=temp1->num;
        int j=i;
        node* temp3=temp1;
        while(1)
        {
           if(temp3->num < min){min=temp3->num;cout<<min<<endl;temp2=temp3;}
           temp3=temp3->next;
           if(temp3==NULL && j==m)break;
           if(temp3==NULL){j++;temp3=a[j];}
        }
        if(temp2!=NULL)
        {
            cout<<temp1->num<<" "<<temp2->num<<endl;
            swap(temp1->num,temp2->num);
        }
           temp1=temp1->next;
           if(temp1->next==NULL && i==m)break;
           if(temp1->next==NULL){i++;temp1=a[i];}            
    }
}

int main()
{
    int m,n,min=-1;
    cin>>m;
    node* a[m];
    for(int i=0;i<m;i++)
    {
        cin>>n;
        if(min=-1)min=n;
        else if(n!=-1 &&  n<min)min=n;
        node* head=new node(n);
        a[i]=head;cin>>n;
        while(n!=-1)
        {
            addend(head,n);
            cin>>n;
        }
    }
    nextmin(a,m);
    int i=0;
    while(i<m)
    {
        node* temp=a[i];
       while(temp)
       {
           cout<<temp->num<<" ";
           temp=temp->next;
       }
       cout<<-1<<" ";
        i++;   
    }
    return 0;
}
