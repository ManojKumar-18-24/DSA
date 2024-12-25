#include<bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    if(s.length()%2!=0)return -1;
    stack<char> M;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='}')
        {
            if(M.size()>=1 && M.top()=='{')M.pop();
            else M.push(s[i]);
        }
        else M.push(s[i]);
    }
    int count=0;
    while(M.size())
    {
        char a=M.top();M.pop();
        char b=M.top();M.pop();
        if((a=='{' && b=='{') || (a=='}' && b=='}'))count++;
        else count+=2;
    }
    return count;
}

int main()
{
 string s;
 cin>>s;
 cout<<countRev(s);
return 0;
}