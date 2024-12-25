#include<iostream>
#include<algorithm>
using namespace std;

int sum(int a[],int n,int i,int j)
{  static int msum=0;
  if(i==j){msum+=a[j];int p=msum;msum=0;cout<<p<<endl;return p;}
  else if(j<i){msum+=a[j];sum(a,n,i,j+1);} 
  else{return 0;}
}

int common(int a[],int b[],int n,int m,int i=0,int j=0)
{  static int msum=0,p=0,q=0;
    if(i==n)
    { //cout<<"sum= ";  
     //cout<<sum(a,n,n-1,p)<<" "<<sum(b,m,m-1,q)<<endl;
     msum+=max(sum(a,n,n-1,p),sum(b,m,m-1,q));
     //cout<<"msum ="<<msum<<endl;
     return msum;
    }
   else if( j==m || b[j]>a[i])
   {  
    common(a,b,n,m,i+1,q);
   }
   else if(a[i]==b[j])
   { //cout<<"sum= ";  
     //cout<<sum(a,n,i,p)<<" "<<sum(b,m,j,q)<<endl;
      msum+=max(sum(a,n,i,p),sum(b,m,j,q));
      //cout<<"msum ="<<msum<<endl;p=i+1;q=j+1;
      common(a,b,n,m,i+1,j+1);
   }
   else
   {
    common(a,b,n,m,i,j+1);
   } 
}

int main()
{
 int n,m;
 cin>>n>>m;
 int a[n],b[m];
 for(int i=0;i<n;i++) cin>>a[i];
 for(int j=0;j<m;j++) cin>>b[j];
  //if(a[0]<=b[0])
   cout<<common(a,b,n,m);
//  else cout<<common(b,a,m,n);
return 0;
}