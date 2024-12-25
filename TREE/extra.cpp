#include<iostream>
#include<vector>
using namespace std;
class trieNode{
public:
trieNode* arr[26];
bool eow;
trieNode(){
    eow=0;
    for(int i=0;i<26;i++){
        arr[i]=NULL;
    }
}
};
typedef trieNode* Tptr;
void add(Tptr &T,string s,int &i){//first i -1;not making eow=1;
    if(!T){
      T=new trieNode();
      i++;
      if(i<s.size())
        add(T->arr[s[i]-'a'],s,i);
    }
    else {
        i++;
        if(i<s.size())
        add(T->arr[s[i]-'a'],s,i);
        }
}
bool helper(Tptr T,string s,int &i){
    if(i==s.size()) return 1;
    if(T&&i<s.size()){
        for(int j=0;j<26;j++){
            if(T->arr[j]){
                if(j==s[i]-'a'){
                    if(T->arr[j]->eow==0){
                    T->arr[j]->eow=1;
                    i++;
                    }
                }
                return helper(T->arr[j],s,i);
            }
        }
    }
    return 0;
}
bool canBreak(Tptr T,vector<string>S){
    int j=0;
 for(int i=0;i<S.size();i++){
    j=0;
    if(!helper(T,S[i],j)) return 0;
 }
 return 1;
}
int main()
{
    vector<string>V;
    string str;
    cin>>str;
    while(str!="#"){
        V.push_back(str);
        cin>>str;
    }
    Tptr T=NULL;int i=-1;
    cin>>str;
    add(T,str,i);
    if(canBreak(T,V))  cout<<"true";
    else cout<<"false";
    return 0;
}