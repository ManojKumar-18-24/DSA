#include<bits/stdc++.h>
using namespace std;

int create(vector<int> &ST,vector<int> &A,int l,int r,int i)
{
   if(l==r)
   {
    ST[i]=A[l];
   }
   else
   {
    int mid=(l+r)/2;
    int n=create(ST,A,l,mid,2*i+1);
    int m=create(ST,A,mid+1,r,2*i+2);
    if(n>1 && m>1)
    {
        if(A[l]<A[r])ST[i]=1;
        else ST[i]=-1;
    }
    else if(m>1)
    {
        if(n==1 && A[mid+1]>A[mid])ST[i]=1;
        else if(n==-1 && A[mid+1]<A[mid])ST[i]=-1;
        else ST[i]=0;
    }
    else if(n==0 || m==0 || n+m==0)
    {
        ST[i]=0;
    }
    else if(n==1 && m==1)
    {
        if(A[mid]<A[mid+1])ST[i]=1;
        else ST[i]=0;
    }
    else if(n==-1 && m==-1)
    {
        if(A[mid]<A[mid+1])ST[i]=-1;
        else ST[i]=0;
    }
   }
    return ST[i];
}

int Get(vector<int> &ST,vector<int>&A,int l,int r,int dl,int dr,int i)
{

  if(dl<=l && dr>=r)return ST[i];
  else if(l>dr || dl>r )return -2;
  else
 {
    int mid=(l+r)/2;
    int n=Get(ST,A,l,mid,dl,dr,2*i+1);
    int m=Get(ST,A,mid+1,r,dl,dr,2*i+2);
    if(m==-2)return n;
    else if(n==-2)return m;
    if(m==0 || n==0 || m+n==0)return 0;
    else if(m==1 && n==1)
    {
        if(A[mid]<A[mid+1])return 1;
        else return 0;
    }
    else if(m==-1 && n==-1)
    {
        if(A[mid]>A[mid+1])return -1;
        else return 0;
    }
    else if((n==1 || n==-1) && m>1)
    {
        if((A[mid+1]>A[mid])*n>0)return n;
        else return 0;
    }
    else if((m==1 || m==-1) && n>1)
    {
        if((A[mid+1]>A[mid])*m>0)return m;
        else return 0;        
    }
 }
}

int main()
{
 vector<int> A;
 int n;
 cin>>n;
 while(n!=-1){   A.push_back(n);   cin>>n;}
 vector<int> ST(32,3);
 create(ST,A,0,A.size()-1,0);
int l,r;
cin>>l>>r;

while(l!=-1 && r!=-1)
{
    cout<<l<<" "<<r<<" Range is";
    switch(Get(ST,A,0,A.size()-1,l,r,0))
    {
        case -1:cout<<" decreasing"<<endl;
        case 0:cout<<" random"<<endl;
        case 1:cout<<" increasing"<<endl;
    }
    cin>>l>>r;
}
return 0;
}