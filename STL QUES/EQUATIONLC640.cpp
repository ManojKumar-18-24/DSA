#include<bits/stdc++.h>
using namespace std;

/*string solveEquation(string equation)
{
    int i=0,j=0,c1=0,c2=0,s1=0,s2=0,p=0;string sub;
  while(1)
  { if( equation.length()-1==i)
       { 
        if(equation[i]!='x'){sub+=equation[i];p++;}
        else
        { 
          if(sub.length()!=0) c1+=stoi(sub);
          else
          {
            if(equation[j]=='+')c1+=1;
            else c1-=1;
          }
          break;
        }
       }
    if(equation[i]=='x' && equation[i-1]=='-'){c1+=-1;j=i+1;if(equation[i+1]=='='){c2=c1;s2=s1;c1=0;s1=0;i++;j++;} }
    if(equation[i]=='x' && equation[i-1]=='+'){c1+=1;j=i+1;if(equation[i+1]=='='){c2=c1;s2=s1;c1=0;s1=0;i++;j++;} }
    if(equation[i]!='+' && equation[i]!='-' && equation[i]!='=' && equation[i]!='x' && p==0)
    {sub+=equation[i];}
    else if(sub.length()>=1 || equation.length()-1==i )
    {      cout<<sub<<endl;
        if(equation[i]=='x')
        {
            if(equation[j]!='-')c1+=stoi(sub);
            else c1-=stoi(sub);j=i+1;i++;
        }
        else
        {
            if(equation[j]!='-')s1+=stoi(sub);
            else s1-=stoi(sub); 
             j=i+1;
        }
        sub.erase(0,sub.length());
        if(equation[i]=='='){c2=c1;s2=s1;c1=0;s1=0;}       
    } i++;
    if(i==equation.length()) break;
  }
/* if(c1==c2 && s1==s2) sub="Infinite solutions";
        else if(c1==c2 && s1!=s2) sub="No solution";
        else{
            int value=(s2-s1)/(c1-c2);
            sub="x="+to_string(value);
        }
    
  cout<<c2<<" "<<s2<<" "<<c1<<" "<<s1<<endl;
  return sub;
}*/

int main()
{
 string s="-456+0+3x-5x=-456+2x"; //3 261 8 -44
 //cout<<solveEquation(s);
return 0;
}