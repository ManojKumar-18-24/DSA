#include<iostream>
#include<vector>
using namespace std;

int a[]={0,0,0,0,0,0,0,0,0,0};

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

void create(trienode* &t,string s,int i=0)
{
   if(t==NULL)
   {
    t=new trienode;
   }
    if(i==s.length())t->eow=1;
    else
    {
        create(t->ptr[s[i]-'a'],s,i+1);
    }
}

trienode* rem=NULL;

void print(trienode *t,vector<string> &input,string s="",int i=0)
{
  if(t!=NULL)
  {
      int count=0;
    for(int j=0;j<26;j++)
    {   
        if(t->ptr[j])
        {
            count++;
            if(i==s.length())s+=" ";
            s[i]=char(j+'a');
            print(t->ptr[j],input,s,i+1);
        }
    }
    if(count>1 && rem!=t)
    {
        for(int j=0;j<26;j++)
        {
            if(t->ptr[j])
            {
              string p=s;p.erase(p.length()-1,1);
              p+=char(j+'a');  
              //cout<<"hi "<<p<<endl;
              for(int k=0;k<input.size();k++)
              {
                if(a[k]==0 && input[k].substr(0,p.length())==p )
                {
                    //cout<<"bye "<<k<<" "<<input[k].substr(0,p.length())<<endl;
                    input[k]=p;
                    a[k]=1;
                    break;
                }
              }
            }
        }
    }
  }
}

int main()
{
 vector<string> input;
 string s;
 cin>>s;
 trienode* t=NULL;
 while(s!="#")
 {
    create(t,s);
    input.push_back(s);
    cin>>s;
 }
 rem=t;
 print(t,input);
 for(int i=0;i<input.size();i++)
 {
    if(a[i]==0)cout<<input[i][0]<<endl;
    else cout<<input[i]<<endl;
 }
return 0;
}