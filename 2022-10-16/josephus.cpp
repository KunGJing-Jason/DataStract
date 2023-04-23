#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

//定义单链表节点
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//函数声明：n为总人数，m表示数到m的人出列
void josephus(int n, int m);
int main(){
    int n,m;
    cin>>n>>m;
    josephus(n,m);
    return 0;
}

void josephus(int n, int m){ //函数实现部分
    int i,j,k;

    int *next = (int *)malloc(n*sizeof(int));

    for(i = 0; i < n-1; i++){
        next[i] = i+1;
    }

    next[n-1] = 0;

    k = n-1;

    for(i = 1; i < n; ++i){
        for(j = 1; j < m; j++){
            k = next[k];
        }
        cout <<  "出列的人是 " << next[k]+1 << endl;
        next[k] = next[next[k]];
    }
    cout << "最终胜出的是 "<<next[k]+1<<endl;

}

