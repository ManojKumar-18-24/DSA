#include<bits/stdc++.h>
using namespace std;

int BuildST(vector<int> &ST,int i,vector<int> A,int l,int r)
{
     if(l==r)
     {
        ST[i]=A[l];
     }
     else
     {
       int mid=(l+r)/2;
       ST[i]=BuildST(ST,2*i+1,A,l,mid)+BuildST(ST,2*i+2,A,mid+1,r);
     }
     return ST[i];
}

int GetSum(vector<int> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i];
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

void Update(vector<int>&ST,int i,int sl,int sr,int position,int diff)
{
     if(sl<=position && position<=sr)ST[i]+=diff;
    if(sl==sr)
    {
        ;
    }
    else
    {
       int mid=(sl+sr)/2;
       Update(ST,2*i+1,sl,mid,position,diff);
       Update(ST,2*i+2,mid+1,sr,position,diff);

    }
}

int main()
{
 vector<int> A;
 int n;
 cin>>n;
 while(n!=-1)
 {
    A.push_back(n);
    cin>>n;
 }
 vector<int> ST(16,0);
 BuildST(ST,0,A,0,A.size()-1);
 for(int i=0;i<16;i++)cout<<ST[i]<<" ";
 cout<<endl;
int l,r;
cin>>l>>r;
while(l!=-1 && r!=-1)
{
    cout<<GetSum(ST,0,0,A.size()-1,l,r)<<endl;
    cin>>l>>r;
}
cin>>l>>r;
Update(ST,0,0,A.size()-1,l,r-A[l]);
for(int i=0;i<16;i++)cout<<ST[i]<<" ";
return 0;
}