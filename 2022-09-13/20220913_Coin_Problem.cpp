//通过已知条件：三种硬币共计50个；三种硬币权重之和等于100；
//x，y，z分别对应1，2，5；
//x+y+z=50;x+2y+5z=100
//得到z关于x和y的函数式
//x=3z；y=50-4z；
//数学模型实现具体如下：
#include <iostream>
using namespace std;

int main (){
    int x,y,z;//分别对应1分、2分、5分；
    for(z=0;z<=20;z++){
        x=3*z;
        y=50-4*z;
        if((x+y+z==50)&&(x+2*y+5*z==100)&&x>=0&&y>=0&&z>=0){
            cout<<"1分："<<x<<","<<"2分："<<y<<","<<"5分："<<z<<endl;
        }
    }
    return 0;
}
