#include<iostream>
#include<utility>
using namespace std;

struct two
{
  int x;
  int y;
};

struct stack
{
  int size=100;
  two elements[100];
  int top=-1;
};

void peep(stack &M)
{
    if(M.top==-1);
    else
    {
        cout<<M.elements[M.top].x<<" "<<M.elements[M.top].y;
    }
}

two pop(stack &M)
{
    if(M.top==-1)
    {
        two p;p.x=-1;p.y=-1;
        return p;
    }
    else
    {
        return M.elements[M.top--];
    }
}

void push(stack &M,two u)
{
    if(M.top==M.size-1);
    else
    {
        M.top++;
        M.elements[M.top].x=u.x;
        M.elements[M.top].y=u.y; 
    }
}

int main()
{
 int n;stack M;cin>>n;
 int a[n];for(int i=0;i<n;i++){cin>>a[i];}
 two r;r.x=0;r.y=n-1;
 push(M,r);
 while(M.top!=-1)
 {
   int pivot,rigth,left;r=pop(M);
   left=r.x;rigth=r.y;int p=rigth,q=left;
   pivot=left;
   while(left<=rigth)
   {
       while(a[pivot]<a[rigth])
       {
           rigth--;
       }
       swap(a[pivot],a[rigth]);pivot=rigth;rigth--;
       while(a[pivot]>a[left])
       {
           left++;
       }
       swap(a[pivot],a[left]);pivot=left;left++;
   }
     r.x=q;r.y=pivot-1;
  if(r.x<r.y) push(M,r);
   r.x=pivot+1;r.y=p;
  if(r.x<r.y) push(M,r);
 }
 for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
 return 0;
}