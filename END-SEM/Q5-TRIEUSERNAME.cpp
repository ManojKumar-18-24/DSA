#include<iostream>
using namespace std;

class trie
{
  public:
  trie* ptr[36]={NULL};
  int eow=0;
  trie()
  {

  }
};

string h;

void create(trie* &head,string s,int i=0)
{
    if(head==NULL)
    {
        head=new trie;
    }
    if(i>=s.length())
    {
        if(head->eow==0)
        { 
            head->eow=1;
            int c=0;
         for(int i=0;i<36;i++)
         {
            if(head->ptr[i]!=0)c++;
         }
         if(c>0)
         {
          for(int i=26;i<36;i++)
          {
             if(head->ptr[i]==NULL)
             {
                create(head->ptr[i],s,i);
                h+=char(i+22);return;
             }
          }            
         }
        }
        else
        {
          for(int i=26;i<36;i++)
          {
             if(head->ptr[i]==NULL)
             {
                create(head->ptr[i],s,i);
                h+=char(i+22);return;
             }
          }
        }
    }
    else
    {
        if(s[i]>='a')create(head->ptr[s[i]-'a'],s,i+1);
        else create(head->ptr[s[i]-22],s,i+1);
    }
}

int main()
{
    string s;
    trie* head=new trie;
    cin>>s;
    while(s!="#")
    {
        create(head,s);
        cout<<s+h<<endl;
        h.erase(0,h.length());
        cin>>s;
    }
    return 0;
}