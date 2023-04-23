#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
}SqList;

Status InitList(SqList L);//Initial
Status GetElem(SqList L,int i,ElemType &e);//Get
int LocateElem(SqList L,ElemType &e);//Find
Status ListInsert(SqList &L,int i,ElemType e);//Insert;
Status ListDelete(SqList &L,int i);//Delete


int main(){
    SqList L;
    InitList(L);
    cout<<L.length;
    cout<<L.elem;
    return 0;
}

//Initial
Status InitList(SqList L){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    return OK;
}

//Get
Status GetElem(SqList L,int i,ElemType &e){
    if(i<1||i>L.length)
        return ERROR;
    e=L.elem[i-1];
    return OK;
}

//Find
int LocateElem(SqList L,ElemType &e){
    for(int i=0;i<L.length;i++){
        if(L.elem[i]==e)
            return i+1;
        }
    return 0;
}

//Insert
Status ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L.length)
        return ERROR;
    if(L.length==MAXSIZE)
        return ERROR;
    for(int j=L.length-1;j>=i+1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}

//DROP
Status ListDelete(SqList &L,int i){
    if((i<1)||(i>L.length))
        return ERROR;
    for(int j=1;j<L.length;j++){
        L.elem[j-1]=L.elem[j];
        --L.length;
        return OK;
    }
}
