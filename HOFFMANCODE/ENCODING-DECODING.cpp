#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct two
{
   int frequency;
   char letter;
};

class tree
{
    public:
    tree* lc;
    two data;
    tree* rc;
    tree(two req)
    {
        lc=NULL;
        data.frequency=req.frequency;
        data.letter=req.letter;
        rc=NULL;
    }
};

vector<tree*> nodecreator(vector<tree*> &h)
{
    vector<tree*> v;
    int i=0;
    for(int i=1;i<=2;i++)
    {
        for(int j=h.size()-1;j>0;j--)
        {
            if(h[j]->data.frequency<h[j-1]->data.frequency)
            {
                swap(h[j],h[j-1]);
            }
        }
    }
    two req;
    req.letter='#';
    req.frequency=h[0]->data.frequency+h[1]->data.frequency;
    tree* g=new tree(req);
    g->lc=h[0];g->rc=h[1];
    for(int i=2;i<h.size();i++)
    {
        v.push_back(h[i]);
    }
    v.push_back(g);
    return v;
}

void print(tree* t,map<char,string> &m,string s="")
{
    if(t!=NULL)
    {
       if(t->data.letter!='#')
       {
         m[t->data.letter]=s;
       }
       print(t->lc,m,s+'0');
       print(t->rc,m,s+'1');
    }
}

void decode(tree* t,string s,int &i)
{
    if(t)
    {
       if(t->data.letter!='#')
       {
         cout<<t->data.letter;
       }  
       else
       {
           if(s[i]=='0')
           {
              i++; 
              decode(t->lc,s,i);
           }
           else
           {
               i++;
               decode(t->rc,s,i);
           }
       }
    }
}

int main()
{
    vector<two> v;
    vector<tree*> storer;
    two req;
    cin>>req.letter>>req.frequency;
    while(req.frequency!=-1 && req.letter!='#')
    {
        v.push_back(req);
        cin>>req.letter>>req.frequency;
    }
    int i=0;
    while(i<v.size())
    {
        tree* g=new tree(v[i]);
        storer.push_back(g);
        i++;
    }
    while(1)
    {
        storer=nodecreator(storer);
        if(storer.size()==1)break;
    }
    map<char,string> m;
    print(storer[0],m);
    string input,output;
    cin>>input;
    for(int i=0;i<input.length()-1;i++)
    {
        for(auto it=m.begin();it!=m.end();++it)
        {
            if((*it).first==input[i])
            {
                output+=(*it).second;
            }
        }
    }
    cout<<output<<endl;
    cin>>input;
     i=0;
    while(i<input.length()-1)
    {
        decode(storer[0],input,i);
    }
    return 0;
}