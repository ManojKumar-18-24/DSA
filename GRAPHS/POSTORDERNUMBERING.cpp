#include<iostream>
using namespace std;

int c=1;

void GivepostNumber(int G[10][10],int V[10],int post[10],int i)
{
    for(int j=0;j<10;j++)
    {
      if(V[j]==0 && G[i][j]==1)
      {
        V[j]=1;
        GivepostNumber(G,V,post,j);
      }
    }
   if(post[i]==0)
   { 
      post[i]=c;
      c++;
   }
    V[i]=1;
}

int main()
{
  int G[10][10]=
     {
        0,1,0,1,0,0,0,0,0,0,
        0,0,1,0,0,1,0,0,0,0,
        1,0,0,1,1,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,0,0,0,0,
        0,0,0,0,0,1,0,1,0,0,
        0,0,0,0,0,0,0,0,0,1,
        0,0,0,0,0,0,0,1,0,0,
        0,0,0,0,0,0,0,0,1,0,
     };
    int V[10]={0,0,0,0,0,0,0,0,0,0};
    int post[10]={0,0,0,0,0,0,0,0,0,0};
    while(1)
    {
        int run=-1;
        for(int i=0;i<10;i++)
        {
           if(post[i]==0){run=i;break;}
        }
        if(run==-1)break;
        GivepostNumber(G,V,post,run);
    }
        for(int i=0;i<10;i++)
        {
           cout<<i+1<<" "<<post[i]<<endl;
        }   
return 0;
}