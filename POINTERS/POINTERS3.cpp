#include<bits/stdc++.h>
using namespace std;

struct s1
{
  int a;
  s2 *b;
};

struct s2
{
  int e;
  s3* f;
};

struct s3
{
 int g;
};

int main()
{
  s1* a;
  a=new(s1);(*a).a=4;
 (*a).b=new(s2);
 a->b->f=new(s3);
 (*(*(*a).b).f).g=7;
 //a->b->
return 0;
}