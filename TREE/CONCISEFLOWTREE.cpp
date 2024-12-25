#include<bits/stdc++.h>
using namespace std;

struct gnode
{
    char ch;
    gnode* fc=NULL;
    gnode* ns=NULL;
};

typedef gnode* gptr;

void construct(gptr &t)
{
    char ch;
    cin>>ch;
    if(ch=='.'){
        return;
    }
    t=new gnode;
    t->ch=ch;
    construct(t->fc);
    construct(t->ns);
}

int passes(gptr t)
{
    if(!t)
    {
        return 0;
    }
    int n=0;
    gptr p=t->fc;
    int m=0;
    while(p)
    {
        n++;
        m=max(m,passes(p));
        p=p->ns;
    }
    return max(m,n);
}

int main()
{
    gptr t=NULL;
    construct(t);
    cout<<passes(t);
}