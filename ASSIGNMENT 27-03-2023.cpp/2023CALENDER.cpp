#include<iostream>
using namespace std;

int main()
{   string a[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    int b[12]={0,3,3,6,1,4,6,2,5,0,3,5};
    int c[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char d[7]={'S','M','T','W','T','F','S'};int p=7,j=0,g;
    cout<<"                       2023 CALENDER  "<<endl<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"      "<<a[j]<<"                       "<<a[j+4]<<"                      "<<a[j+8]<<endl<<endl;
        for(int k=1;k<=3;k++)
		{
		for(int l=0;l<7;l++)cout<<d[l]<<"  "; cout<<" ";
	    } cout<<endl; g=j;
	for(int k=0;k<6;k++)
	    {
	      if(k==0)
		  { for(int r=1;r<=3;r++)
		    {
			for(int l=0;l<b[g];l++) cout<<"   ";
	    	for(int l=1;true;l++)
	    	{
	    	  if(l<10)cout<<"0";cout<<l;cout<<" "; if(b[g]+l==7) break;
			} cout<<" ";g+=4;
		    }
		    g=j;cout<<endl;
		 }
	     else
		{
			   g=j;
		  
		  for(int r=1;r<=3;r++)
		  	{
		  	   	for(int l=p-b[g]+1;l<=p-b[g]+7;l++)
		  	   	{   
		  	   		if(l<=c[g]){
					if(l<10)cout<<"0";cout<<l<<" ";}else cout<<"   ";
				} cout<<" ";g+=4;
			} cout<<endl;
	       
			p+=7;
		}
	    }
	    j+=1;p=7;
	}
	return 0;
}