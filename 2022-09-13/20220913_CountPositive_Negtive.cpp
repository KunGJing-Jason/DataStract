#include<iostream>
using namespace std;

int main(){
    int positive=0;
    int negative=0;

    int *p = new int[10];

    for(int i=0;i<10;i++){
        cin>>p[i];
        if(p[i]!=0){
            p[i]>0?positive++:negative++;
        }
    }

    cout<<"正数:"<<positive<<endl<<"负数:"<<negative;

    return 0;
}
