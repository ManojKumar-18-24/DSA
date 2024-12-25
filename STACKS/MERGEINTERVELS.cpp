#include<iostream>
#include<algorithm>
using namespace std;

struct two 
{ 
    int x; 
    int y; 
    
}; 

struct stack { 
    int size;
    two elements[100]; 
    int top; 
}; 

void peep(stack &M)
{
    if(M.top==-1);
    else {
        cout<<M.elements[M.top].x<<" "<<M.elements[M.top].y; }
} 

two pop(stack &M) {
    if(M.top==-1) 
    { 
        two p;p.x=-1;p.y=-1; return p; 
        
    } 
    else {
        return M.elements[M.top--];
        } 
}

void push(stack &M,two& u) {
    if(M.top==M.size-1); 
    else
    { 
        M.top++; M.elements[M.top].x=u.x; M.elements[M.top].y=u.y;
    } 
    
}

void merge(stack&M,two &r)
{   
    if(M.top==-1)
    {
        push(M,r);
    }
    else
    {
        two p=pop(M);
        if(p.x<=r.y)
        {   
            r.x=min(r.x,p.x);
            r.y=max(r.y,p.y);
            merge(M,r);
        }
        else
        {
            two q=r;
            r=p;
            merge(M,r);
            push(M,q);
        }
    }
}

void read(stack &M)
{  two p;    cin>>p.x>>p.y;
    if(p.x==-1 && p.y==-1);
    else
    {
        read(M);
        push(M,p);
    }
}
    
int main()
{
    stack M; 
    M.top=-1;
    M.size=100;
     read(M);
    two r=pop(M);
    merge(M,r);
    while(M.top!=-1)
    {
        two r=pop(M);
        cout<<r.x<<" "<<r.y<<" ";
    }
    return 0; 
}