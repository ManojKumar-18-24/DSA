#include<iostream>
#include<vector>
using namespace std;
class Queue{
    public:
    char* arr;
    int front,rear,size;
    Queue(int sz){
        front=-1;rear=-1;size=sz;
        arr=new char[sz];
    }
    void disp(){
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<arr[rear]<<endl;
    }
    bool empty(){
        return (front==-1||rear==-1);
    }
    bool full(){
       return (rear+1)%size==front;
    }
    void enQ(char x){
        if(full()){
            cout<<"Q is full"<<x<<endl;
            return ;
        }
        if(empty()){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=x;
    }
    char deQ(){
          char t='#';
        if(empty()){
            cout<<"q is Empty";
            return t;
        }
        t=arr[front];
        if(front==rear){
            front=rear=-1;;
        }
        front=(front+1)%size;
        return t;
            }
};
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'){
        return true;
    }
    return false;
}
bool isNum(char c){
    return (c>='0'&&c<='9');
}
int evaluate(Queue &Q){
    int ans=0;
    char c1=Q.deQ();
    char c2=Q.deQ();
    char c3;
    if(c2=='#'){
        return c1-'0';
    }
    // c3=Q.deQ();
    while(!Q.empty()){
            c3=Q.deQ();
         if(isOperator(c1)&&isNum(c2)&&isNum(c3)){
                int n2=c2-'0',n3=c3-'0';
                if(c1=='+'){
                    Q.enQ(char(n2+n3+'0'));
                    Q.disp();
                }
                else if(c1=='-'){
                    Q.enQ(char(n2-n3+'0'));
                }
                else if(c1=='*'){
                    Q.enQ(char((n2*n3)+'0'));
                    Q.disp();
                }
                else if(c1=='/'){
                    Q.enQ(char((n2/n3)+'0'));
                }
                if(!Q.empty())
                c1=Q.deQ();
                if(!Q.empty())
                c2=Q.deQ();
        }
        else{
            Q.enQ(c1);
            c1=c2,c2=c3;
        }
    }
    cout<<"1";
    if(c1=='#'&&Q.empty()){
        return c2-'0';
    }
    return ans;
}
int main(){
    string str="-+*9+28*+4863";
    Queue Q(100);
    for(int i=0;i<str.size();i++){    Q.enQ(str[i]);}
    Q.enQ('#');
    cout<<evaluate(Q);
    return 0;
}