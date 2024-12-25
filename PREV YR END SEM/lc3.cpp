#include<bits/stdc++.h>
using namespace std;
   
    int lengthOfLongestSubstring(string s) 
    {
      if(!s.length())return 0;
      set<char> visit;
      int low=0,high=1,max=1,count=1;
      visit.insert(s[low]);
      while(high<s.length())
      {
          if(!visit.count(s[high]))
          {
              visit.insert(s[high]);
              count++;
          }
          else
          {
              if(count>max)max=count;cout<<count<<endl;
              int i;
              for(i=low;i<high;i++)
              {
                  if(s[i]==s[high])break;
                  visit.erase(s[i]);
                  count--;
              }
              low=i++;
          }
          high++;
      }
       if(count>max)max=count;
      return max;
    }

int main()
{
  cout<<lengthOfLongestSubstring("aabaab!bb");
return 0;
} 