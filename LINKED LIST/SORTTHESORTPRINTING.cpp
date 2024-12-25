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

int nextmin(node* a[],int m,int min)
{
    int i=0,dif=0, r=-1;
    while(i<m)
    {
        node* temp=a[i];
       while(temp)
       {
           if(temp->num>min)
           {
               if(dif==0)
               {
                   dif=temp->num-min;
                   r=temp->num;
               }
               else if(temp->num-min<dif)
               {
                   dif=temp->num-min;r=temp->num;
               }
           }
           temp=temp->next;
       }
        i++;   
    }
    return r;
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
    cout<<min<<" ";
    while(1)
    {
        n=nextmin(a,m,min);
        if(n!=-1)cout<<n<<" ";
        else break;
        min=n;
    }
    return 0;
}