#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> v)
{
    string p;
    int count=-1;
    for(int i=0;i<s.length();i++)
    {
        p+=s[i];
        for(int j=0;j<v.size();j++)
        {
             if(p==v[j])
            {
                count=i;
                cout<<p<<endl;
                p.erase(0,p.length());
                break;
            }
        }
    }
    cout<<count;
    if(count==s.length()-1) return true;
     return false;
}

int main()
{
 string s;
 cin>>s;
 vector<string> v;
 while(s!="#")
 {
    v.push_back(s);
    cin>>s;
 }
 cin>>s;
 if(wordBreak(s,v))cout<<"true";
 else cout<<"false";
 return 0;
}