#include<bits/stdc++.h>
using namespace std;

int EqualOrNot(string s,string adder,string given)
{
    int i=0;
    while(i<s.length())
    {
        if(s[i]==' ')
        {
            s.erase(i,1);
        }
        else i++;
    }
    string p=given.substr(0,s.length()+adder.length());
    if(p==s+adder)return true;
    return false;
}

int Getlength(string s,string adder)
{ int i=0;
  int count=0;
    while(i<s.length())
    {
        if(s[i]!=' ')count++;
        i++;
    }
    return count+adder.length();
}

void Combinations(vector<string> v,string given,string s="",int i=0)
{
  if(i==given.length())
  {
    s.erase(0,1);
    cout<<s<<endl;
  }
  else
  {
    for(int j=0;j<5;j++)
    {
        if(v[j][0]==given[i] && EqualOrNot(s,v[j],given) )
        {
            int m=Getlength(s,v[j]);
           Combinations(v,given,s+" "+v[j],m);
        }
    }
  }
}

int main()
{
 string s;
 cin>>s;
 vector<string> v;
 v.push_back(s);cin>>s;
 while(s!="#")
 {
    v.push_back(s);
    cin>>s;
 }
 cin>>s;
 Combinations(v,s);
 return 0;
}