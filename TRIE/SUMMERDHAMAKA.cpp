#include<bits/stdc++.h>
using namespace std;

class tree
{
  public:
  string s;
  tree* ptr[26];
  int eow;
  tree(string t)
  {
    s=t;
    eow=0;
    for(int i=0;i<26;i++)ptr[i]=NULL;
  }
};

void Add(tree* &t,string s)
{
    if(t==NULL)
    {
        t=new tree(s);
        t->eow=1;
    }
    else
    {
        if(t->s=="")Add(t->ptr[s[0]-'A'],s);
        else
        {
            int m=(t->s).length(),n=s.length();
            if(m<n)
            {
                if(s.substr(0,m)==t->s)
                {   string h=s.substr(m,n-m);
                    Add(t->ptr[h[0]-'A'],h);
                }
                else
                {
                    int i;
                   for( i=0;i<m;i++)
                   {
                     if((t->s)[i]!=s[i])break;
                   }
                   string  h=(t->s).substr(i,m-i);
                   t->s=(t->s).substr(0,i);
                   t->ptr[h[0]-'A']=new tree(h);if(t->eow==1)t->ptr[h[0]-'A']->eow=1;t->eow=0;
                   for(int j=0;j<26;j++)
                   {
                       if(t->ptr[j] && t->ptr[j]!=t->ptr[h[0]-'A'])
                       {
                           t->ptr[h[0]-'A']->ptr[j]=t->ptr[j];
                           t->ptr[h[0]-'A']->ptr[j]->eow=1;
                           t->ptr[j]=NULL;
                       }
                   }
                    h=s.substr(i,n-i);
                   Add(t->ptr[h[0]-'A'],h);
                }
            }
            else
            {
                if((t->s).substr(0,n)==s)
                { 
                    string h=t->s.substr(n,m-n);
                     t->s=s;
                    t->ptr[h[0]-'A']=new tree(h);
                    t->ptr[h[0]-'A']->eow=1;
                   for(int i=0;i<26;i++)
                   {
                       if(t->ptr[i] && t->ptr[i]!=t->ptr[h[0]-'A'])
                       {
                           t->ptr[h[0]-'A']->ptr[i]=t->ptr[i];
                           t->ptr[h[0]-'A']->ptr[i]->eow=1;
                           t->ptr[i]=NULL;
                       }
                   }
                }
                else
                { int i;
                   for( i=0;i<m;i++)
                   {
                     if((t->s)[i]!=s[i])break;
                   }    
                   string h=(t->s).substr(i,m-i);
                   t->eow=0;
                   t->ptr[h[0]-'A']=new tree(h);
                   t->ptr[h[0]-'A']->eow=1;
                   for(int j=0;j<26;j++)
                   {
                       if(t->ptr[j] && t->ptr[h[0]-'A']!=t->ptr[j])
                       {
                           t->ptr[h[0]-'A']->ptr[j]=t->ptr[j];
                           t->ptr[h[0]-'A']->ptr[j]->eow=1;
                           t->ptr[j]=NULL;
                       }
                   }                   
                   h=(t->s).substr(0,i);
                   t->s=h;
                   h=s.substr(i,n-i);
                   t->ptr[h[0]-'A']=new tree(h);
                   t->ptr[h[0]-'A']->eow=1;
                }
            }
        }
    }
}

int c=0;

void print(tree* t,string s)
{
    if(t)
    {  c++;
       if(t->eow==1) cout<<s+t->s<<endl;
        for(int i=0;i<26;i++)
        {
            print(t->ptr[i],s+t->s);
        }
    }
}

int main()
{
    string s;
    cin>>s;
    tree* t=new tree("");
    while(s!="#")
     {
      Add(t,s);
      cin>>s;
     }     
     print(t,"");
     cout<<c;
    return 0;
}
