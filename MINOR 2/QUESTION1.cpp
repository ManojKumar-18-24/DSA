#include<bits/stdc++.h>
using namespace std;

int BuildST(vector<int> &ST,int i,vector<int> A,int l,int r)
{
     if(l==r)
     {
        if(A[l]==0)ST[i]=1;
        else ST[i]=0;
     }
     else
     {
       int mid=(l+r)/2;
       ST[i]=BuildST(ST,2*i+1,A,l,mid)+BuildST(ST,2*i+2,A,mid+1,r);
     }
     return ST[i];
}

int GetNumber(vector<int> ST,int i,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r) return ST[i];
    if(sr<l || sl>r)
    {
        return 0;
    }
    else
    {
        int mid=(sl+sr)/2;
        return(GetNumber(ST,2*i+1,sl,mid,l,r)+GetNumber(ST,2*i+2,mid+1,sr,l,r));
    }
    return 0;
}

int main()
{
 vector<int> A;
 int flag;char ch;
 cin>>flag;
 while(flag!=-1 || ch!='#')
 {
    if(flag==0)
    {
        cin>>flag;
        if(flag==-1)break; 
        A.push_back(0);
        cin>>flag;
    }
    else
    {
        cin>>ch;
        if(ch=='#')break; 
        A.push_back(1);
        cin>>flag;
    }
 }
 vector<int> ST(100,0);
 BuildST(ST,0,A,0,A.size()-1);
int l,r;
cin>>l>>r;
while(l!=-1 && r!=-1)
{
    int t=GetNumber(ST,0,0,A.size()-1,l,r);
    cout<<t<<" "<<r-l+1-t<<endl;
    cin>>l>>r;
}
return 0;
}
