#include<iostream>
using namespace std;
int Factorial(int x);
int main (){
    int num,sum=0;
    cin>>num;

    if(num>20){
        return 0;
    }
    int *p = new int[num];

    for(int i=1;i<=num;i++){
        p[i]=i;
        sum+=Factorial(i);
    }

    cout<<sum;
}

int Factorial (int x){
    int multiple=1;
    for (int i = 1; i <=x; i++)
    {
        multiple*=i;
    }
    return multiple;
}