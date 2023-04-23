/****************************************************************************************/
/*          作者 ： 陈龙                                                                */
/*          程序 ： 双栈数据结构                                                        */
/*          测试用例                                                                    */
/*                    7                                                                 */
/*                    3 4 2 2                                                           */
/*                    1 2 3                                                             */
/*                    4 5 6 7                                                           */
/*          输出用例 ：                                                                 */
/*                    YES                                                               */
/*                    3  2                                                              */
/*                    NO                                                                */
/*                    7  6                                                              */
/*                    NO                                                                */
/*          参数说明 ： len_s：bot[0]-top[0]的长度；                                    */
/*                      len_t: top[1]-bot[1]的长度                                      */
/*                      pop_1:bot弹出个数、pop_2:top弹出个数                            */
/*          函数说明                                                                    */
/*          初始化：  将bot[0]=top[0] = -1,bot[1]=top[1]=m，初始化空栈                  */
/*          栈空：    判断bot[0]==top[0]或bot[1]==top[1]，则空栈                        */
/*          栈满：    判断top[0]+1==top[1]就是当中间的top长度为2（仅首尾俩元素），则空满*/
/*          入栈：    根据进入的双栈情况判断，对于不同栈入栈方式不同，
                        bot - top则是top[0]++，
                        top-bot则是top[1]--，若已经满栈，则不能继续入栈                 */
/*          出栈：    根据出栈的情况判断，对于不同栈出栈方式不同，
                        bot - top则是top[0]--，
                        top-bot则是top[1]++，若已经空栈，则不能继续出栈                 */
/****************************************************************************************/



#include <iostream>
using namespace std;

#define MAX 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef int SElementType;
typedef int Status;

typedef struct 
{
    int top[2], bot[2];
    SElementType *V;
    int m;
}DblStack;

Status InitDblStack(DblStack &S, int m);
Status IsEmpty(DblStack S, int i);
Status IsFull(DblStack S);
Status PushDbStack(DblStack &S, int num, int i);
Status PopDbStack(DblStack &S, int i, int &num);

int main(){
    int n;
    DblStack S;
    while(cin >> n){
        int len_s, len_t, pop_1, pop_2;
        int num;
        InitDblStack(S,n);
        cin >> len_s >> len_t >> pop_1 >> pop_2;

        for (int i = 0; i < len_s; i++){
            cin >> num;
            PushDbStack(S, num, 0);
        }

        for (int i = 0; i < len_t; i++){
            cin >> num;
            PushDbStack(S, num, 1);
        }

        cout << (IsFull(S)? "Yes":"No")<< endl;

        for (int i = 0; i < pop_1; i++){
            PopDbStack(S, 0, num);
            cout << num <<"  ";
        }

        cout << endl << (IsEmpty(S,0)? "No":"Yes")<< endl;

        for (int i = 0; i < pop_2; i++){
            PopDbStack(S, 1, num);
            cout << num <<"  ";
        }

        cout << endl << (IsEmpty(S,0)? "No":"Yes")<< endl;
        
        
    }
    return 0;
}


Status InitDblStack(DblStack &S, int m){
    S.V = new int[m];
    if(!S.V)
        return OVERFLOW;
    S.bot[0] = S.top[0] = -1;
    S.bot[1] = S.top[1] = m;
    return OK;
}

Status IsEmpty(DblStack S, int i){
    if(S.bot[i] == S.top[i])
        return 0;
    else
        return 1;
}

Status IsFull(DblStack S){
    if(S.top[0]+1 == S.top[1])
        return 1;
    else
        return 0;
}

Status PushDbStack(DblStack &S, int num, int i){
    if(S.top[1] - S.top[0] == 1) 
	  return ERROR;
	if(i == 0){
		S.top[0]++;
		S.V[S.top[0]] = num;  
	}
	else {
		S.top[1]--;
		S.V[S.top[1]] = num;		
	}
	return OK;
}

Status PopDbStack(DblStack &S, int i, int &num){
    if(S.top[i] == S.bot[i])
        return ERROR;
    if(i == 0){
        num = S.V[S.top[i]];
        S.top[0]--;
    }
    else if(i == 1){
        num = S.V[S.top[1]];
        S.top[1]++;
    }
    return OK;
}