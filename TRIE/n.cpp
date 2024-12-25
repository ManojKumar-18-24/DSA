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

int h=0,length=0;

void print(trienode *t,string e,string s="",int i=0)
{
    //cout<<s<<endl;
  if(t!=NULL)
  {
     if(length==e.length())h++;
     if(h==0)
     {
        length++;
           if(i==s.length())s+=" ";
            s[i]=e[length-1];
        print(t->ptr[e[length-1]-'a'],e,s,i+1);
        return;
     }
    if(t->eow==1)cout<<s<<" ";
    for(int j=0;j<26;j++)
    {
        if(t->ptr[j])
        {
            if(i==s.length())s+=" ";
            s[i]=char(j+'a');
            print(t->ptr[j],e,s,i+1);
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
 cin>>s;
 while(s!="#")
 {
    s.erase(s.length()-1.1);
    print(t,s);
    h=0;length=0;
    cin>>s;
 } 
return 0;
}
