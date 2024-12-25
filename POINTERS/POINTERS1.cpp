#include<bits/stdc++.h>
using namespace std;

struct s
{
    int x;
    int y;
    char d;
};

int main()
{
  s* e;
  e=new(s);
  e->d=50;
  cout<<(*e).d;
return 0;
}