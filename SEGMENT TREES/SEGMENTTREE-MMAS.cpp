#include<bits/stdc++.h>
using namespace std;

struct four
{
  int minimum=0;
  int maximum=0;
  int sum=0;
  float average=0;
};

int SumBuildST(vector<four> &ST,int i,int A[],int l,int r)
{
     if(l==r)
     {
        ST[i].sum=A[l];
        ST[i].average=ST[i].sum;
     }
     else
     {
       int mid=(l+r)/2;
       ST[i].sum=SumBuildST(ST,2*i+1,A,l,mid)+SumBuildST(ST,2*i+2,A,mid+1,r);
       float n=ST[i].sum,m=r-l+1;
       ST[i].average=n/m;
     }
     return ST[i].sum;
}

int MinBuildST(vector<four> &ST,int i,int A[],int l,int r)
{
     if(l==r)
     {
        ST[i].minimum=A[l];
     }
     else
     {
       int mid=(l+r)/2;
       ST[i].minimum=min(MinBuildST(ST,2*i+1,A,l,mid),MinBuildST(ST,2*i+2,A,mid+1,r));
     }
     return ST[i].minimum;
}

int MaxBuildST(vector<four> &ST,int i,int A[],int l,int r)
{
     if(l==r)
     {
        ST[i].maximum=A[l];
     }
     else
     {
       int mid=(l+r)/2;
       ST[i].maximum=max(MaxBuildST(ST,2*i+1,A,l,mid),MaxBuildST(ST,2*i+2,A,mid+1,r));
     }
     return ST[i].maximum;
}

void Update(vector<four>&ST,int A[],int i,int sl,int sr,int position,int diff)
{
     if(sl<=position && position<=sr)
     {
        ST[i].sum+=diff;
       float n=ST[i].sum,m=sr-sl+1;
       ST[i].average=n/m;
        if(A[position]>ST[i].maximum){cout<<"hi";ST[i].maximum=A[position];}
        if(A[position]<ST[i].minimum){cout<<"hi";ST[i].minimum=A[position];}             
     }
    if(sl==sr)
    {
           if( sl==position)
       {
        ST[i].maximum=A[position];
        ST[i].minimum=A[position];
       } return;
    }
        int mid=(sl+sr)/2;
       Update(ST,A,2*i+1,sl,mid,position,diff);
       Update(ST,A,2*i+2,mid+1,sr,position,diff);
}

int GetSum(vector<four> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i].sum;
    if(sr<l || sl>r)
    {
        return 0;
    }
    else
    {
        int mid=(sl+sr)/2;
        return(GetSum(ST,2*i+1,sl,mid,l,r)+GetSum(ST,2*i+2,mid+1,sr,l,r));
    }
    return 0;
}

int GetMin(vector<four> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i].minimum;
    if(sr<l || sl>r)
    {
        return 9999;
    }
    else
    {
        int mid=(sl+sr)/2;
        return min(GetMin(ST,2*i+1,sl,mid,l,r),GetMin(ST,2*i+2,mid+1,sr,l,r));
    }
    return 0;
}

int GetMax(vector<four> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i].maximum;
    if(sr<l || sl>r)
    {
        return -9999;
    }
    else
    {
        int mid=(sl+sr)/2;
        return max(GetMax(ST,2*i+1,sl,mid,l,r),GetMax(ST,2*i+2,mid+1,sr,l,r));
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
   vector<four> ST(25);
   MinBuildST(ST,0,A,0,n-1);
   MaxBuildST(ST,0,A,0,n-1);
   SumBuildST(ST,0,A,0,n-1);int queries;
   cin>>queries;
   int p,q,r,diff;
   float d,m;
   while(queries--)
   {
     cin>>p>>q>>r;
     switch(p)
     {
      case 0:
       diff=r-A[q];
      A[q]=r;
      Update(ST,A,0,0,n-1,q,diff);
      break;
      case 1:
      r=GetMin(ST,0,0,n-1,q,r);
      if(r==1)cout<<2<<endl;
      else cout<<r<<endl;
      break;
      case 2:
      cout<<GetMax(ST,0,0,n-1,q,r)<<endl;
      break;
      case 3:
      cout<<GetSum(ST,0,0,n-1,q,r)<<endl;
      break;
      case 4:
       d=GetSum(ST,0,0,n-1,q,r);m=(r-q+1);
      cout<<d/m<<endl;
      break;
     }
   }
return 0;
}