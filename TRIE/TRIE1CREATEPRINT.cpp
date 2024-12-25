#include<iostream>
using namespace std;

class trienode
{
  public:
  trienode* ptr[26];
  int eow;
  trienode()
  {
    eow=0;
    for(int i=0;i<26;i++)ptr[i]=NULL;
  }
};

void add(trienode* &t,string s,int i=0)
{
   if(t==NULL)
   {
    t=new trienode;
   }
    if(i==s.length())t->eow=1;
    else
    {
        add(t->ptr[s[i]-'a'],s,i+1);
    }
}

int count(trienode *t)
{
  int m=0;
  if(t!=NULL)
  {
    if(t->eow==1)m+=1;
    for(int j=0;j<26;j++)
    {
        if(t->ptr[j])
        {
          m+=count(t->ptr[j]);
        }
    }
  }
  return m;
}

void print(trienode *t,string s="",int i=0)
{
  if(t!=NULL)
  {
    if(t->eow==1)cout<<s<<" ";
    for(int j=0;j<26;j++)
    {
        if(t->ptr[j])
        {
            if(i==s.length())s+=" ";
            s[i]=char(j+'a');
            print(t->ptr[j],s,i+1);
        }
    }
  }
}

int main()
{
 string s;
 cin>>s;
 trienode* t=NULL;
 while(s!="#")
 {
    add(t,s);
    cin>>s;
 }
 cout<<count(t)<<endl;
 print(t);
return 0;
}