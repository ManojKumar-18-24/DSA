#include<bits/stdc++.h>
using namespace std;

    string solveEquation(string equation) 
    {
        int g=0,l=equation.length()-1,c1=0,c2=0,s1=0,s2=0,i=0;
        string h;
        while(1)
        {    
            if(equation[g]!='+' && equation[g]!='-' && equation[g]!='=') h+=equation[g];
            else if(h.length()>=1)
            { cout<<h<<endl;
             if(i==0)
             {
                 if(equation[g-1]=='x')
                 {  if(h[0]=='x') 
                     {
                         if(equation[0]!='-')  c1+=1;
                         else c1-=1;                       
                     }
                    else if(h.length()>2)
                        { 
                         h.erase(h.length()-1,1);
                         if(equation[0]!='-')  c1+=stoi(h);
                         else c1-=stoi(h);
                        }
                 }
                else
                {   
                         if(equation[0]!='-')  s1+=stoi(h);
                         else s1-=stoi(h);                     
                }
                h.erase(0,h.length());
                i=g+1;
             }
             else
             {
                 if(equation[g-1]=='x')
                 {  if(h[0]=='x') {
                                    h[0]='1';
                                 }
                    else if(h.length()>1){ h.erase(h.length()-1,1);}
                    if(equation[i-1]!='-')c1+=stoi(h);
                    else c1-=stoi(h);
                 }
                else
                {
                     if(equation[i-1]!='-') s1+=stoi(h);
                     else s1-=stoi(h);
                }
                h.erase(0,h.length());
                i=g+1;              
             }
            }
            if(equation[g]=='=') break;
            g++;
        }
        g++;i=g; h.erase(0,h.length());
        while(1)
        {    
            if(equation[g]!='+' && equation[g]!='-' && g!=l) h+=equation[g];
            else if(h.length()>=1 || g==l)
            {   if(g==l){h+=equation[g];g++;}
                cout<<h<<endl;
              if(equation[i-1]=='=')
               {
                 if(equation[g-1]=='x')
                 {  if(h[0]=='x') {
                                   if(equation[i]!='-')c2+=1;else {c2+=-1;}
                                  }
                    else if(h.length()>2)
                        { 
                           h.erase(h.length()-1,1);
                            if(equation[i]!='-')c2+=stoi(h);else {c2+=stoi(h);}
                        }
                 }
                else if(h.length()>=1)
                {   
                     if(equation[i]!='-') s1+=stoi(h);
                     else s1-=stoi(h);                    
                }
                h.erase(0,h.length());
                i=g+1;
             }
             else
             {
                 if(equation[g-1]=='x')
                 {  if(h[0]=='x') h[0]='1';
                    else{ h.erase(h.length()-1,1);}
                    if(equation[i-1]=='+')c2+=stoi(h);
                    else c2-=stoi(h);
                 }
                else
                {
                     if(equation[i-1]=='+') s2+=stoi(h);
                     else s2-=stoi(h);
                }
                h.erase(0,h.length());
                i=g+1;              
             }
            }
            if(g==equation.length()) break;
            g++;
        }       
        if(c1==c2 && s1==s2) h="Infinite solutions";
        else if(c1==c2 && s1!=s2) h="No solution";
        else{
            int value=(s2-s1)/(c1-c2);
            h="x="+to_string(value);
        }
        cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
        return h;
    }
    
int main()
{ string h="5";
 cout<<stoi(h);
return 0;
}