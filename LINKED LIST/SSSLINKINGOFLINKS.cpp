#include<iostream>
using namespace std;

union two
{
 int x;
 char y;
};

class node
{
 public:
 int flag;
 two m;
 node* next;
  node()
  {
    next=NULL;
  }
};

class store
{
    public:
 node* remember;
 store* next;
 store()
 {  
    remember=NULL;
    next=NULL;
 }
};

void addtostore(store* head,node* temp)
{
    if(head->next==NULL && head->remember==NULL)
    {
        head->remember=temp;return;
    }
    while(head->next!=NULL)
    {
      head=head->next;
    }
    store * g=new store;
    g->remember=temp;
    head->next=g;
}

void addend(node* head,int p)
{
 while(head->next!=NULL)
 {
    head=head->next;
 }
 node* g=new node;
 g->flag=p;
 if(p==1)cin>>g->m.x;
 else cin>>g->m.y;
 head->next=g;
}

void printing(node* head,store* inthead,store* charhead)
{
   node* temp;
   store* inttemp=inthead;
   store* chartemp=charhead;
   while(1)
   {
     temp=inttemp->remember;
     if(chartemp==NULL)
     {
        while(temp!=NULL){cout<<temp->m.x<<" ";temp=temp->next;}
        cout<<endl;
        break;
     }
     while(temp!=chartemp->remember)
     {
        cout<<temp->m.x<<" ";temp=temp->next;
     }
     inttemp=inttemp->next;
     chartemp=chartemp->next;
   }
    inttemp=inthead->next;;
    chartemp=charhead;
   while(1)
   {
       temp=chartemp->remember;
       if(inttemp==NULL)   
       {
        while(temp!=NULL)
        {
            cout<<temp->m.y<<" ";temp=temp->next;
        }
        break;
        } 
       while(temp!=NULL && temp!=inttemp->remember)
       {
        cout<<temp->m.y<<" ";temp=temp->next;
       }
       inttemp=inttemp->next;
     chartemp=chartemp->next;
     if(chartemp==NULL)break;
   }
}

int main()
{
    node* head=new node;
    int p;
    cin>>p;
    head->flag=p;
    if(p==1)cin>>head->m.x;
    else cin>>head->m.y;
    cin>>p;
    while(p!=-1)
    {
      addend(head,p);
      cin>>p;
    }
    store*  inthead=new store;
    store* charhead=new store;
    if(head->flag==1)
    {
        inthead->remember=head;
        node* temp=head;
        temp=temp->next;
        while(1)
        {
            while(temp!=NULL && temp->flag!=0)
            {
                temp=temp->next;
            }
            if(temp==NULL)break;
            addtostore(charhead,temp);
            temp=temp->next;
            while(temp!=NULL && temp->flag!=1)
            {
                temp=temp->next;
            }if(temp==NULL)break;
            addtostore(inthead,temp);
            temp=temp->next;
        }
    }
    else
    {
        charhead->remember=head;
        node* temp=head;
        temp=temp->next;
        while(1)
        {
            while(temp!=NULL && temp->flag!=1)
            {
                temp=temp->next;
            } if(temp==NULL)break;
            addtostore(inthead,temp);
            temp=temp->next;
            while(temp!=NULL && temp->flag!=0)
            {
                temp=temp->next;
            }
            if(temp==NULL)break;
            addtostore(charhead,temp);
            temp=temp->next;  
        }
    }
   printing(head,inthead,charhead); 
    return 0;
}