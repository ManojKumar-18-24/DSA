#include<bits/stdc++.h>
using namespace std;
//q is in nesting stl in luv channel

int main()
{
 int noofstu;
 cin>>noofstu;
 map<int,set<string>> m;
 while(noofstu--)
 {
    string s;int r;
    cin>>s>>r;
    m[r].insert(s);
 }

 auto it=m.end();
 
 while(1)
 {   it--;
    auto &at=(*it).second;
    for(auto y=at.begin();y!=at.end();++y)
    {
        cout<<(*y)<<" "<<(*it).first<<endl;
    }
    if(it==m.begin()){break;}
 }


return 0;
}