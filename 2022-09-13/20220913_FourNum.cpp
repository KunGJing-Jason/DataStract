#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int num=0;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++){
            if(i!=j){
                num=i*1000+i*100+j*10+j;
                if((sqrt(num))==((int)sqrt(num))){
                    cout<<num;
                    return 0;
                }
            }
        }
    return 0;
}