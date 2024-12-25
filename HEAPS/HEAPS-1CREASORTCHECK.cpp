#include<bits/stdc++.h>
using namespace std;

void heapyup(int a[100],int child)
{
    int parent=(child-1)/2;
    if(parent>=0)
    {
        if(a[parent]>a[child])
        {
           swap(a[parent],a[child]);
           heapyup(a,parent);
        }
    }
}

void Sortedprint(int a[100])
{
    cout<<a[0]<<" ";
    int i=0;
    if(a[1]==0)
    {
        a[0]=0;
        return;
    }
    while(a[i+1]!=0)i++;
    a[0]=a[i];
    a[i]=0;
}

void SetHeap(int a[100],int parent=0)
{
    int min=a[parent];
    int leftchild=2*parent+1;
    int rightchild=2*parent+2;
    if(a[leftchild]!=0 && a[leftchild]<min)
    {
       min=a[leftchild];
    }
    if(a[rightchild]!=0 && a[rightchild]<min)
    {
       min=a[rightchild];
    }
    if(min!=a[parent])
    {
        if(min==a[leftchild])
        {
            swap(a[parent],a[leftchild]);
            SetHeap(a,leftchild);
        }
        else
        { 
            swap(a[parent],a[rightchild]);
            SetHeap(a,rightchild);
        }
    }
}

int HeapCheck(int a[100],int parent=0)
{
    int leftchild=2*parent+1;
    int rightchild=2*parent+2;
    int m,n;
    if(!a[leftchild] && !a[rightchild])return 1;
    if(!a[leftchild])
    {
        if(a[rightchild]>a[parent])return 1;
    }
    if(!a[rightchild])
    {
        if(a[leftchild]>a[parent])return 1;
    }
    if(a[leftchild]>a[parent]&&a[rightchild]>a[parent])
    {
         m=HeapCheck(a,leftchild);
         n=HeapCheck(a,rightchild);
        return min(n,m);
    }
    return 0;
}

int main()
{
 int a[100]={0};
 int n;cin>>n;int i=0;
 while(n!=-1)
 {
    a[i]=n;
    i++;
    heapyup(a,i-1);
    cin>>n;
 }
 while(1)
 {
    Sortedprint(a);
    if(a[0]==0)break;
    SetHeap(a);
 }
 cin>>n; i=0;
 while(n!=-1)
 {
    a[i]=n;
    i++;
    cin>>n;
 }
 cout<<HeapCheck(a);
return 0;
}