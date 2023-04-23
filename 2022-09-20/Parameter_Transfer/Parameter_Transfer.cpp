//* & пн╡н
#include<iostream>
using namespace std;
void swap_point(float *m, float *n);
void swap_quote(float &m, float &n);
void swap_nomal(float m, float n);
int main(){
    float a,b,*p1,*p2;
    cin>>a>>b;
    p1=&a;p2=&b;
    swap_nomal(a,b);
    cout<<a<<" "<<b<<endl;
    swap_point(p1,p2);
    cout<<a<<" "<<b<<endl;
    swap_quote(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}

void swap_point(float *m, float *n){
    float temp;
    temp=*m;
    *m=*n;
    *n=temp;
}
void swap_quote(float &m, float &n){
    float temp;
    temp=m;
    m=n;
    n=temp;
}
void swap_nomal(float m, float n){
    float temp;
    temp=m;
    m=n;
    n=temp;
}
