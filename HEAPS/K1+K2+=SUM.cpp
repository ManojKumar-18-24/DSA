#include<iostream>
#include<vector>
using namespace std;

void heapydown(vector<vector<int>> &a,int i,int child)
{
    int parent=(child-1)/2;
    if(parent>=0)
    {
        if(a[i][parent]<a[i][child])
        {
           swap(a[i][parent],a[i][child]);
           heapydown(a,i,parent);
        }
    }
}

void FindMax(vector<vector<int>> a,vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {

    }
}

void AddNnumbers(vector<vector<int>> a,vector<int> &v,int sum)
{
    int addition=0;
    for(int i=0;i<v.size();i++)
    {
        addition+=a[i][v[i]];
    }
    if(addition==sum)
    {
    for(int i=0;i<v.size();i++)
    {
        cout<<a[i][v[i]]<<" ";
    }
     cout<<endl;
    }

}

int main()   
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
               cin>>a[i][j];
               heapydown(a,i,j);
        }
    }
    vector<int> v(n,0);
    int sum;
    cin>>sum;
    return 0;
}