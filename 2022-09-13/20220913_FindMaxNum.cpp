#include <iostream>
using namespace std;

int main(){
    int numsize,max,numlocl;
    cin>>numsize;
    int*p=new int[numsize];
    for(int i=0;i<numsize;i++)
        cin>>p[i];

    max=p[0];
    numlocl = 0;

    for(int i=0;i<numsize;i++){
        if(max<=p[i]){
            max=p[i];
            numlocl=i;
        }
    }

    cout<<max<<" "<<numlocl;

    return 0;

}
