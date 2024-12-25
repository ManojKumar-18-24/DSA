#include<bits/stdc++.h>
using namespace std;

    vector<int> lexicalOrder(int n)
    {
        vector<int> v;
        for(int i=1;i<=9;i++)
        {
           int m=i;
           if(m<=n)v.push_back(m);
           else break;
           int product=i*10;
           m=product;
           int count=0;
           while(m<=n)
           {
                v.push_back(m);
                m++;
                count++;
                if(count==product)
                {
                    product*=10;
                    count=0;
                    m=product;
                }
           }
        }
        return v;
    }

int main()
{
   vector<int> g=lexicalOrder(34);
return 0;
}