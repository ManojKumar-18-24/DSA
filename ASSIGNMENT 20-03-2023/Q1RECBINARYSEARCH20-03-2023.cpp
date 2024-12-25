#include<iostream>
using namespace std;

int binary_search(int a[],int key,int n,int low=0)
{ static int high=n-1;
    int mid=(low+high)/2;
    if(high==low && key!=a[mid]) return -1;
    else if(key==a[mid]) return mid;
    else if(key<a[mid]){high=mid-1;binary_search(a,key,n,low);}
    else if(key>a[mid]){low=mid+1;binary_search(a,key,n,low);} 
}
int main()
{
  int n;cin>>n;int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int key;cout<<"key? ";cin>>key;
  cout<<binary_search(a,key,n);
return 0;
}