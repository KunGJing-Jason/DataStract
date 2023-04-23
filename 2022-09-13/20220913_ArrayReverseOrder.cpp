#include<iostream>
using namespace std;

int main(){
    int *p = new int[10];
    int temp;
    for (int i = 0; i < 10; i++)
    {
        cin>>p[i];
    }

    for(int i=0;i<5;i++){
        temp = p[i];
        p[i] = p[10-i-1];
        p[10-i-1] = temp;
    }

    for(int i=0;i<10;i++){
        if(i!=9){
            cout<<p[i]<<" ";
        }else{
            cout<<p[i];
        }
    }
    
}

