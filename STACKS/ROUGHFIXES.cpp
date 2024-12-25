#include<iostream>
#include<algorithm>
using namespace std;

struct stack
{
  int size;
  string elements[100];
  int top;
};

string peep(stack &M)
{
  return  (M.top==-1)?"":M.elements[M.top];
}

string pop(stack &M)
{
    return ( M.top==-1)?"": M.elements[M.top--];
}

void push(stack &M,string x)
{
  if(M.top==M.size-1);
  else
  { 
    M.top++;
    M.elements[M.top]=x;
  }
}

int prese(stack &M,string ch)
{ if(peep(M)=="(" || ")")return true;
  if(M.top==-1)return true;
  if(ch=="("|| ")")
    return true;
  if(ch=="+" || ch=="-")
  {
    if(peep(M)=="*" || "/" || "+")
    {
        return false;
    }
    return true;
  }
  if(ch=="*")
  {
     if(peep(M)=="/")return false;
     return true;
  }
    if(ch=="/")
  {
     if(peep(M)=="*")return false;
     return true;
  }
}

void infixtopostfix(stack&M,string s)
{
   for(int i=0;i<s.length();i++)
   {
     if(s[i]>=65 && s[i]<93)
     {
        cout<<s[i];
     }
     else
     {
        if(s[i]!=')')
       {   if(prese(M,to_string(s[i])))
            {
               push(M,to_string(s[i]));
            }
            else
            { 
              while(M.top!=-1) 
              { 
                if(peep(M)=="("){break;}
                cout<<pop(M);
              } 
             if(peep(M)=="(") string h=pop(M);
             push(M,to_string(s[i]));
            }
       }
       else
       {  
          while(M.top!=-1) 
            {  if(peep(M)=="(")break;
                cout<<pop(M);
            } 
           if(peep(M)=="(") string h=pop(M);        
       }
     }
   }  
          while(M.top!=-1) 
            {  if(peep(M)=="("){pop(M);break;}
                cout<<pop(M);
            } 
}

/*void infixtoprefix(stack &M,string s)
{
  string a;
  for(int i=s.length()-1;i>=0;i++)
  {
    if(s[i]>=65 && s[i]<=92)
    {
      a+=s[i];
    }
    else
    {
      if(s[i]==')')
      {
        push(M,s[i]);
      }
      else if(s[i]=='(')
      {
        while(M.top!=-1)
        { 
          int ch=peep(M);
          if(peep(M)=='('){pop(M);break;}
          else if(!prese(M,pop(M)))a+=pop(M);
          else push(M,ch);
        }
      }
      else
      {
         



         
      }
    }
  }


}
*/

void prefixtoinfix(stack& M,stack &S,string s)
{ int c=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]>='A' && s[i]<='Z')
    { string p;p+=s[i];
      push(S,p);p.erase(0,p.length());
    }
  }

}


int main()
{
 stack  M,S;
 M.top=-1;S.top=-1;
 M.size=100;S.size=100;
 string s;cin>>s;
 infixtopostfix(M,s);
 //infixtoprefix(M,s);

return 0;
}