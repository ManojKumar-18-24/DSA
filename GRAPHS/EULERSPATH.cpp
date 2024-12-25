#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int num)
    {
        data=num;
        next=NULL;
    }
};

void addend(node* &LPTR,int n)
{
  if(LPTR==NULL)
  {
    LPTR=new node(n);return;
  }
  node* temp=LPTR;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  node* L=new node(n);
  temp->next=L;
}

void print(node* head)
{
  while(head)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

void addmiddle(node* head,node* temp)
{
  print(head);print(temp);
   while(head->data!=temp->data)head=head->next;
   node* temp1=head->next;
   head->next=temp->next;
   node* temp2=temp;
   while(temp2->next!=NULL)temp2=temp2->next;
   temp2->next=temp1;
}

void Change(int G[12][12],int source,node* head)
{
     node* temp=NULL;
     int i;
     addend(temp,source+1);
     for( i=0;i<12;i++)
     { 
      if(G[source][i]==1) 
      {   addend(temp,i+1);G[source][i]=0;G[i][source]=0;source=i;i=0; }}
     addmiddle(head,temp);
}

int main()
{
  int G[12][12]={0};
  G[1][2]=1;G[2][1]=1;G[1][7]=1;G[7][1]=1;
  G[7][8]=1;G[8][7]=1;G[5][8]=1;G[8][5]=1;
  G[2][5]=1;G[5][2]=1;G[2][8]=1;G[8][2]=1;
  G[2][0]=1;G[0][2]=1;G[0][3]=1;G[3][0]=1;
  G[2][3]=1;G[3][2]=1;G[2][6]=1;G[6][2]=1;
  G[3][6]=1;G[6][3]=1;G[6][8]=1;G[8][6]=1;
  G[6][9]=1;G[9][6]=1;G[3][9]=1;G[9][3]=1;
  G[8][9]=1;G[9][8]=1;G[8][11]=1;G[11][8]=1;
  G[9][11]=1;G[11][9]=1;G[3][4]=1;G[4][3]=1;
  G[3][10]=1;G[10][3]=1;G[4][9]=1;G[9][4]=1;
  G[9][10]=1;G[10][9]=1;
  int source;
  cin>>source;
  node* head=new node(source);
  Change(G,source-1,head);
  node* temp=head;
  print(head);
  while(temp)
  {
    for(int i=0;i<12;i++)
    {
      if(G[temp->data-1][i])
      { 
          print(head);
          Change(G,temp->data-1,head);
          temp=head;
          continue;
      }
    }
     temp=temp->next;   
  }   
return 0;
}