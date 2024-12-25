#include<bits/stdc++.h>
using namespace std;

void HeapyUp(int a[100],int child)
{
    int parent=(child-1)/2;
    if(parent>=0)
    {
        if(a[parent]>a[child])
        {
            swap(a[parent],a[child]);
            HeapyUp(a,parent);
        }
    }
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

void Print(int a[100])
{
    int j=0;
    while(a[j]!=0)
    {
        cout<<a[j]<<" ";
        j++;
    }
    cout<<endl; 
}

int main()
{
 int k;
 cin>>k;
 int a[100]={0};
 int i=0,n;
 cin>>n;
 while(n!=-1)
 {
    a[i]=n;
    if(i<k)
    {
         HeapyUp(a,i);
         i++;
    }
    else
     {
        if(a[i]>a[0])
        {
           a[0]=a[i];
        }
         a[i]=0;
        SetHeap(a);
     }
    Print(a);
    cin>>n;
 }

return 0;
}