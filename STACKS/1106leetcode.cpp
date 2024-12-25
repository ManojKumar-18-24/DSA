#include<bits/stdc++.h>
using namespace std;

   void evaluate(stack<int>& eval)
    {
       int truecount=0,falsecount=0;
       char top=eval.top();
       while(top!='(')
       {
           if(top=='t')truecount++;
           if(top=='f')falsecount++;
           eval.pop();
           top=eval.top();
       }
       eval.pop();
       top=eval.top();
       if(top=='&')
       {
           if(falsecount)eval.push('f');
           else  eval.push('t');
       }
       else if(top=='|')
       {
           if(truecount)eval.push('t');
           else eval.push('f');
       }
       else
       {
           if(falsecount)eval.push('t');
           else  eval.push('f');   
       }
    }

    bool parseBoolExpr(string exp) 
    {
        stack<int> eval;
        for(int i=0;i<exp.length();i++)
        {
           if(exp[i]==',');
           else if(exp[i]!=')')
           {
              eval.push(exp[i]);
           }
           else
           {
             evaluate(eval);
           }
        }
        if(eval.size()>1)evaluate(eval);
        char top=eval.top();
        if(top=='t')return true;
        return false;
    }

int main()
{
 string str="&(|(f))";
 cout<<parseBoolExpr(str);
return 0;
}