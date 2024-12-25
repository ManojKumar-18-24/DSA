#include<iostream>
using namespace std;
struct bstnode{
    int data;
    bstnode* lc;
    bstnode* rc;
};
typedef bstnode* BSTPTR;
void create(BSTPTR &T,int k){
   if(T==NULL){
      T=new(bstnode);
      T->data=k;
      T->lc=NULL;
      T->rc=NULL;
   }
   else{
    if(k<T->data){
        create(T->lc,k);
    }
    else{
        create(T->rc,k);
    }
   }
}
void inorder(BSTPTR T){
    if(T==NULL){
       
        return;
    }
    else{
       
        inorder(T->lc);
         cout<<T->data<<" ";
        inorder(T->rc);
    }
}
void ser_preorder(BSTPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        if(T->lc==NULL){
            cout<<0<<" ";
        }
        if(T->rc==NULL){
            cout<<0<<" ";
        }
        ser_preorder(T->lc);
        ser_preorder(T->rc);
    }
}
BSTPTR construct(int A[],int i,int size){
     static BSTPTR T;
    T=new(bstnode);
    static BSTPTR S;
    S=new(bstnode);
    //T=NULL;
       if(i<size){
        if(A[i]!=0){if(i==0){
            S=T;
        }
               T->data=A[i];
               cout<<T->data<<" "<<i<<" "<<size<<endl;
           }
           T->lc=NULL;
            T->rc=NULL;
           i++;
           }
            T->lc=construct(A,i,size);
            T->rc=construct(A,i,size);
       return S;
}// 5 8 3 6 7 4 9 1 2 -1
int main(){
BSTPTR T;
T=new(bstnode);
T=NULL;
int x;
while(true){
    cin>>x;
    if(x==-1){
        break;
    }
    else{
        create(T,x);
    }
}
ser_preorder(T);
cout<<endl;
int A[]={5,3,1,0,2,0,0,4,0,0,8,6,0,7,0,0,9,0,0};

BSTPTR B;
B=new(bstnode);
B=construct(A,0,sizeof(A)/4);
//inorder(B);
return 0;
}