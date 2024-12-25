#include<bits/stdc++.h>
using namespace std;

struct two
{
    int even,odd;
};

int BuildST(vector<two> &ST,int i,vector<int> &A,int l,int r)
{
     if(l==r)
     {
        if(A[l]%2==0)
        {
            ST[i].even=1;
            ST[i].odd=0;
        }
        else
        {
            ST[i].odd=1;
            ST[i].even=0;           
        }
     }
     else
     {
       int mid=(l+r)/2;
       ST[i].even=BuildST(ST,2*i+1,A,l,mid)+BuildST(ST,2*i+2,A,mid+1,r);
       ST[i].odd=r-l+1-ST[i].even;
     }
     return ST[i].even;
}

int Geteven(vector<two> &ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i].even;
    if(sr<l || sl>r)
    {
        return 0;
    }
    else
    {
        int mid=(sl+sr)/2;
        return Geteven(ST,2*i+1,sl,mid,l,r)+Geteven(ST,2*i+2,mid+1,sr,l,r);
    }
    return 0;
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
 vector<two> ST(30);
 BuildST(ST,0,A,0,A.size()-1);
int l,r;
cin>>l>>r;
for(int i=0;i<ST.size();i++)
while(l!=-1 && r!=-1)
{
    int t=Geteven(ST,0,0,A.size()-1,l,r);
    cout<<t<<" "<<r-l+1-t;
    cin>>l>>r;
}
return 0;
}