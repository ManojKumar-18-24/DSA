#include<iostream>
using namespace std;

int count=0;

struct two
{
    int x,y;
};

struct queue
{
 int size=50,front=-1,rear=-1;two elements[50];
};

bool is_qfull(queue Q)
{
  if((Q.rear+1)%Q.size==Q.front)
  return true;
  return false;
}

bool is_qempty(queue Q)
{  
  if(Q.front==-1 && Q.rear==-1)
  {return true;}
  return false;
}

void enq(queue& Q,two t)
{
    if(is_qfull(Q))
    {
      cout<<"it's full";
    }
    else
    {
     if(Q.front==-1)Q.front++;
     Q.rear=(Q.rear+1)%Q.size;
     Q.elements[Q.rear].x=t.x;
     Q.elements[Q.rear].y=t.y;
    }
}

two deq(queue &Q)
{
 if(is_qempty(Q))
 {
  cout<<"it's empty";
 }
 else
 { 
  two n=Q.elements[Q.front];
  if(Q.front==Q.rear)
  {
    Q.front=-1;Q.rear=-1;
  }
  else
  {
    Q.front=(Q.front+1)%Q.size;
  }
  return n;
 }
}

int main()
{  
  queue Q;two r;int count=0, i,j;
   r.x=0;r.y=0;enq(Q,r);
    int a[10][10]=  {     
                      {1,0,1,0,0,0,1,1,1,1},
                      {0,0,1,0,1,0,1,0,0,0},
                      {1,1,1,1,0,0,1,0,0,0},
                      {1,0,0,1,0,1,0,0,0,0},
                      {1,1,1,1,0,0,0,1,1,1},
                      {0,1,0,1,0,0,1,1,1,1},
                      {0,0,0,0,0,1,1,1,0,0},
                      {0,0,0,1,0,0,1,1,1,0},
                      {1,0,1,0,1,0,0,1,0,0},
                      {1,1,1,1,0,0,0,1,1,1},
                    };
    int v[10][10]={0};
     while(1)
     {
        r=deq(Q);
        cout<<r.x<<" "<<r.y<<endl;
        v[r.x][r.y]=1;
        while(1)
        {
            if(r.y+1<10 && v[r.x][r.y+1]==0 && a[r.x][r.y+1]==1)
            {
                v[r.x][r.y+1]=1;r.y++;enq(Q,r);r.y--;enq(Q,r);break;
            }
            if(r.x+1<10 && v[r.x+1][r.y]==0 && a[r.x+1][r.y]==1)
            {
                v[r.x+1][r.y]=1;r.x++;enq(Q,r);r.x--;enq(Q,r);break;
            }
            if(r.y-1>=0 && v[r.x][r.y-1]==0 && a[r.x][r.y-1]==1)
            {
                v[r.x][r.y-1]=1;r.y--;enq(Q,r);r.y++;enq(Q,r);break;
            }
            if(r.x-1>=0 && v[r.x-1][r.y]==0 && a[r.x-1][r.y]==1)
            {
                v[r.x-1][r.y]=1;r.x--;enq(Q,r);r.x++;enq(Q,r);break;
            }
            if(r.y+1<10 && r.x+1<10 && v[r.x+1][r.y+1]==0 && a[r.x+1][r.y+1]==1)
            {
                v[r.x+1][r.y+1]=1;r.y++;r.x++;enq(Q,r);r.x--;r.y--;enq(Q,r);break;
            }
            if(r.y-1>=0 && r.x-1>=0 && v[r.x-1][r.y-1]==0 && a[r.x-1][r.y-1]==1)
            {
                v[r.x-1][r.y-1]=1;r.y--;r.x--;enq(Q,r);r.y++;r.x++;enq(Q,r);break;
            }
            if(r.y-1>=0 && r.x+1<10 && v[r.x+1][r.y-1]==0 && a[r.x+1][r.y-1]==1)
            {
                v[r.x+1][r.y-1]=1;r.y--;r.x++;enq(Q,r);r.y++;r.x--;enq(Q,r);break;
            }
            if(r.y+1<10 && r.x-1>=0 && v[r.x-1][r.y+1]==0 && a[r.x-1][r.y+1]==1)
            {
                v[r.x-1][r.y+1]=1;r.y++;r.x--;enq(Q,r);r.y--;r.x++;enq(Q,r);break;
            }
            break;
        }
        if(is_qempty(Q))
        {     count++;
              cout<<"count= "<<count<<endl;
              for( i=0;i<10;i++)
              {     int c=0;int j;
                for( j=0;j<10;j++)
                {
                    if(a[i][j]==1 && v[i][j]==0)
                    {
                        r.x=i;r.y=j;
                        cout<<"i&j= "<<i<<" "<<j<<endl;
                        enq(Q,r);c++;break;
                    }
                }
                if(c>0){break;}
                if(i==9 && j==9){ if(c==0 && a[i][j]==1 && v[i][j]==0)count++;}
              }
              cout<<"MATRIX: "<<endl;
              for(int w=0;w<10;w++) { for(int z=0;z<10;z++){ cout<<v[w][z]<<" ";}cout<<endl;}      
        }
       if(i==9 && j==9)break;
     }

  cout<<"special count "<<count<<endl;

    return 0;
}