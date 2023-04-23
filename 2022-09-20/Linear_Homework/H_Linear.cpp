#include <iostream>
using namespace std;

typedef int Status;
struct Number{
	int Number;
};

typedef struct{
    Number *elem;
    int length;
}Linear;

Status InitList(Linear &L,int NumSize);
Status InputList(Linear &L,int numSize);
Status DeleList(Linear &L, int x,int y);

int main(){
    int NumSize,x,y;
    Linear L;

    cin>>NumSize;
    InitList(L,NumSize);
    InputList(L,NumSize);

    cin>>x>>y;

    DeleList(L,x,y);

    for(int i=0;i<L.length;i++){
        if(i!=L.length-1){
            cout<<L.elem[i].Number<<" ";
        }else{
            cout<<L.elem[i].Number;
        }
    }

    return 1;

}

//Initial
Status InitList(Linear &L,int NumSize){
    if(!NumSize){
        cout<<"NULL";
        return 0;
    }
    L.elem = new Number[NumSize];
    L.length=NumSize;
    return 1;
}

//Input
Status InputList(Linear &L,int numSize){
	
    for(int i=0;i<numSize;i++){
        cin>>L.elem[i].Number;
    }
    return 1;
}

//Delete
Status DeleList(Linear &L, int x,int y){
    if(L.length==0){
        cout<<"NULL";
        return 0;
    }

     for (int i = 0; i < L.length; i++){
        if((L.elem[i].Number>=x)&&(L.elem[i].Number<=y)){
            for(int j=i+1;j<=L.length;j++)
            L.elem[j-1]=L.elem[j];
            --L.length;
            --i;
        }     
    }
    
    return 1;
    
}
