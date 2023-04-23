#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX_SIZE 100
#define OK 0
#define ERROR 1
typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType* data;     //指向首地址的指针
    int maxSize;        //最大长度
    int length;         //线性表当前长度
}SqList;

Status InitList(SqList &L);
void DestoryList(SqList &L);
void ClearList(SqList &L);
Status IsListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L, int i);
int LocateElem(SqList L, int e);
Status PriorList(SqList L, int cur_e, int &pre_e);
Status NextList(SqList L, int cur_e, int &next_e);
Status InsertList(SqList &L, int i, int e);
Status DeleteList(SqList &L, int i, int &e);
void PrintList(SqList L);

int main(){
    SqList L;
    int ListSize=0; 
    int delete_Value=0, Insert_Value=0;
    int pre_e=0, next_e=0, cur_e=0;
    InitList(L);

    cout << "Please Input the length of List. "<<endl;
    cin >> ListSize; 
    while(ListSize>MAX_SIZE){
        cout << "The Size is too big please reinput" << endl;
        cin >> ListSize;
    }

    cout << "Please input the nums" << endl;

    for(int i = 0; i < ListSize; i++){
        cin >> Insert_Value;    
        InsertList(L,i,Insert_Value);
    }

    cout << "The List is :";
    PrintList(L);

    return 0;
}

Status InitList(SqList &L){
    L.maxSize = MAX_SIZE ;
    L.data = new ElemType[MAX_SIZE];
    if(!L.data)
        return ERROR;
    L.length = 0;
    return OK;
}

void DestoryList(SqList &L){
    if(L.data)
        delete L.data;
}

void ClearList(SqList &L){
    L.length = 0;
}

Status IsListEmpty(SqList L){
    if(!L.length)
        return ERROR;
    else
        return OK;
}

int ListLength(SqList L){
    return L.length;
}

Status GetElem(SqList L, int i){
    if(i < 1 ||i > L.length)
        return ERROR;
    else
        return L.data[i-1];
}

int LocateElem(SqList L, int e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e)
            return i;
    }
    return ERROR;
}

Status PriorList(SqList L, int cur_e, int &pre_e){
    for(int i = 1; i < L.length; i++){
        if(L.data[i] == cur_e){
            pre_e = L.data[i-1];
            return OK;
        }
    }
    return ERROR;
}

Status NextList(SqList L, int cur_e, int &next_e){
    for(int i = 0; i < L.length-1; i++){
        if(L.data[i] == cur_e){
            next_e = L.data[i+1];
            return OK;
        }
    }
    return ERROR;
}

Status InsertList(SqList &L, int i, int e){
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length >= MAX_SIZE)
        return ERROR;
    for (int j = L.length; j >= i; j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1] = e;
    ++L.length;
    return OK;    
}

Status DeleteList(SqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.data[ i - 1 ];
    for(int j = i;j < L.length; j++){
        L.data[j-1]=L.data[j];
    }
    --L.length;
    return OK;
}

void PrintList(SqList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}