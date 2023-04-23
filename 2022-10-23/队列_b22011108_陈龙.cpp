/****************************************************************************************/
/*          作者 ： 陈龙                                                                */
/*          程序 ： 循环队列                                                            */
/*          测试用例                                                                    */
/*                    1 2 3 4 5 6 7 8                                                  */
/*                    EOF                                                              */
/*          输出用例 ：                                                                 */
/*                    8 7 6 5 4 3 2 1                                                   */
/*          参数说明 ： e:数据                                                          */
/*          函数说明                                                                    */
/*          初始化：  将Q.font = Q.rare = Q.tar = 0，初始化空队列                        */
/*          入队：    判断队列是否满队，满队不入队，Q.Q[Q.rare] = e
                        将数据入到队尾
                        Q.rare = (Q.rare+1)%MAX，队尾指针+1                              */
/*          出队：    判断Q.tar == 0，空队不出队
                        e =Q.Q[Q.front]，引用类型取队头元素，(Q.front+1)%MAX，头指针+1    */
/****************************************************************************************/
#include<iostream>
using namespace std;

#define MAX 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef int Status;

typedef struct{
    int tar;
    int fornt;
    int rare;
    int *Q;
}SqQune;

Status InitSqQune(SqQune &Q);
Status enqueue(SqQune &Q, int e);
Status dequeue(SqQune &Q, int &e);

int main(){
    int num, pop_num, count;
    SqQune Q;
    InitSqQune(Q);

    while(cin >> num){
        if(enqueue(Q,num)){
            cout << "Succes!" <<endl;
            ++count;
        }else{
            cout << "Fail" <<endl;
            break;
        }
    }
    
    while(count--){
        dequeue(Q,pop_num);
        cout << pop_num <<endl;
    }
    
    return 0;
}

Status InitSqQune(SqQune &Q){
    Q.Q = new int [MAX];
    if(!Q.Q)
        return ERROR;
    Q.fornt = Q.rare = Q.tar = 0;
    return OK;
}


Status enqueue(SqQune &Q, int e){
    if(((Q.rare + 1) % MAX) == Q.fornt)
        return ERROR;   //队满不入队
    Q.Q[Q.rare] =e;
    Q.rare = (Q.rare + 1) % MAX;

    if(Q.tar == 0)
        Q.tar = 1;      //队列不为空
    return  OK;
}

Status dequeue(SqQune &Q, int &e){
    if(Q.tar == 0 && Q.fornt == Q.rare)
        return ERROR;
    e = Q.Q[Q.fornt];
    Q.fornt = (Q.fornt + 1) % MAX;
    return OK;
}