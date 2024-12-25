#include<iostream>
using namespace std;

struct S10
{
  int y;
  S10* z;
};

struct S9
{
  S9* w;
  int x;
};

struct S8
{
 S9* t;
 int u;
 S10* v;
};

struct S6
{
 int n;
 char o;
 S8* p;
};

struct S7
{
 S6* q;
 int r;
 S7* s;
};

struct S5
{
  int l;
  S7* m;
};

struct S4
{
 S6* j;
 S5* k; 
};

struct S3
{
 S4* g;
 S3* h;
 S5* i;
};

struct S2
{
 char e;
 S3* f;
};

struct S1
{
    S1* a;
    int b;
    S2* c;
    S1* d;
};

int main()
{
   S1 *sone;
   sone=new(S1);
   sone->a=sone;
   sone->d=sone;
   sone->c=new(S2);
   sone->c->f=new(S3);
   sone->c->f->h=sone->c->f;
   sone->c->f->g=new(S4);
   sone->c->f->i=new(S5);
   sone->c->f->g->j=new(S6);
   sone->c->f->g->k=sone->c->f->i;
   sone->c->f->i->m=new(S7);
   sone->c->f->i->m->q= sone->c->f->g->j;
   sone->c->f->i->m->s=sone->c->f->i->m;
   sone->c->f->g->j->p=new(S8);
   sone->c->f->g->j->p->t=new(S9);
   sone->c->f->g->j->p->v=new(S10);
   sone->c->f->g->j->p->t->w=sone->c->f->g->j->p->t;
   sone->c->f->g->j->p->v->z=sone->c->f->g->j->p->v;
   cin>>sone->b>>sone->c->f->i->m->r>>sone->c->f->i->m->q->p->u;
   if(sone->c->f->i->m->q->p->u%2==0)
   {
    sone->c->f->i->m->q->p->t->x=sone->b;
    sone->c->f->i->m->q->p->v->y=sone->c->f->i->m->r;
   }
   else
   {
    sone->c->f->i->m->q->p->t->x=sone->c->f->i->m->r;
    sone->c->f->i->m->q->p->v->y=sone->b;
   }
   cout<<sone->b<<" "<<sone->c->f->i->m->r<<" "<<sone->c->f->i->m->q->p->u<<" "<<sone->c->f->i->m->q->p->t->x<<" "<<sone->c->f->i->m->q->p->v->y;
    return 0;
}