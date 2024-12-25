#include<iostream>
using namespace std;


int pop(int a[],int b[],int c[],int k)
{
   if(c[k]==b[k]-1) 
   {
       cout<<"empty";
   }
   else
   {
       return a[c[k]--];
   }
}

void push(int a[],int b[],int c[],int k,int x)
{
  if(c[k]==b[k+1]-1);
  else
  { 
   c[k]++;
   a[c[k]]=x;
  }
}

int main()
{
    int k,n;cin>>k>>n;
    int a[n],b[k+2],c[k];b[0]=0;b[k+1]=n-1;c[0]=-1;
    for(int i=1;i<=k;i++){cin>>b[i];if(i!=k)c[i]=b[i]-1;}
    int d,e,f;
    cin>>d>>e>>f;
    while(d!=-1 && e!=-1 && f!=-1)
    {
      if(e==1)
      {
          push(a,b,c,d,f);
      }
      else
      {
        pop(a,b,c,d);
      }
      cin>>d>>e>>f;
    }
   int  i=0;
    while(i<k)
    {  cout<<i<<" ";
        while(c[i]!=b[i]-1)
        {
           cout<< pop(a,b,c,i)<<" ";
        }
        i++;
        cout<<endl;
    }
    
    
    return 0;
}

