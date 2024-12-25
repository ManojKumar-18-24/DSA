#include<iostream>
#include<vector>
using namespace std;
struct tnode{
    tnode* ptr[26];
    int eow;
};
typedef tnode* TPTR;
void create(TPTR &T,string S,int i){
      if(T==NULL)
      {
        T=new(tnode);
        for(int j=0;j<26;j++)
        {
            T->ptr[j]=NULL;
            T->eow=0;
        }
        if(i==S.size()) T->eow=1;
        else create(T->ptr[S[i]-'a'],S,i+1);
      }
      else
      {
       if(i==S.size()) T->eow=1;
        else create(T->ptr[S[i]-'a'],S,i+1);
      }
}
bool isfound(TPTR T,string &S,int i)
{
    if(T!=NULL)
    {
        if(i==S.size()) return true;
        else
        {
        if(T->ptr[S[i]-'a']) 
        {
            isfound(T->ptr[S[i]-'a'],S,i+1);
        }
        else return false;
        }
    }
}
void Delete(TPTR &T,TPTR &A,string S,int i){
   if(T!=NULL)
    {   if(i==S.size())
        { A=new(tnode);
            A=T;
            return ;}
        else    Delete(T->ptr[S[i]-'a'],A,S,i+1);
    }
}
bool word_break(TPTR T,vector<string>&v)
{        TPTR A;
    for(int i=0;i<v.size();i++)
    {          
        if(isfound(T,v[i],0)) 
        {      A=new(tnode);
            Delete(T,A,v[i],0);
            T=A;
        }    
        else return false;
    }
    return true;
}
int main(){
    TPTR T;
    T=new(tnode);
    T=NULL;
    string S;
    vector<string>v;
    while(true){
        cin>>S;
        if(S=="#")break;
        v.push_back(S);
    }
  cin>>S;
  create(T,S,0);
  if(word_break(T,v)) cout<<"true";
  else cout<<"false";
  return 0;
}