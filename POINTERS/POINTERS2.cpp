#include<bits/stdc++.h>
using namespace std;

struct s1
{
 float r;
 char name[10];
};

struct s
{
    int x;
    int y;
    s1* w;
    char d;
};

int main()
{
  s* e;
  e=new(s);
  e->w=new(s1);
  e->w->r=56.89;
  cout<<(*((*e).w)).r;
return 0;
}