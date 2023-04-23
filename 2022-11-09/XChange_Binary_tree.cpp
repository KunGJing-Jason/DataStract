/******************************************************************/
/*     作者 ： 陈龙                                                */
/*     程序 ： 交换左子树和右子树                                   */
/*     测试用例：                                                  */
/*            ABC##DE#G##F###                                    */
/*            ACB##DE#G##F###                                     */
/*                                                                */
/*     输出 :                                                     */
/*            A"BDF""EG"""C"       A"CDF""EG"""B"                 */
/*     函数说明                                                   */
/*            Auto_CreateBinaryTree     自动生成树                */
/*            Manual_CreateBinaryTree   手动生成树                */
/*            XChange_SubTree           交换左右子树对应元素        */
/*                                                                */
/******************************************************************/

#include <iostream>
using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
    
}BiTNode, *BiTree;

char Test_One[15] = {'A','B','C','#','#','D','E','#','G','#','#','F','#','#','#'};
char Test_Two[15] = {'A','C','B','#','#','D','E','#','G','#','#','F','#','#','#'};
int i = 0;                                  //用于自动输入测试用例
char ch;                                    //输入字符

void Auto_CreateBinaryTree(BiTree &T,char Test[]);
void Maual_CreateBinaryTree(BiTree &T);
void DisplayBinaryTree(BiTree T);
bool XChange_SubTree(BiTree &T);

int main(){
    int Test_Mode = 0;                             //测试模式
    BiTree tree1, tree2;
    cout << "请输入测试模式，1为自动测试，0为手动输入" << endl;

    cin >> Test_Mode;

    if(Test_Mode == 1){
        Auto_CreateBinaryTree(tree1,Test_One);
        i = 0;                                  //下标清零，不然数组会越界报错;
        Auto_CreateBinaryTree(tree2,Test_Two);
        i = 0;
        if(XChange_SubTree(tree1)){
            DisplayBinaryTree(tree1);
            cout << endl;
        }
        else{
            cout << "是空树！" << endl;
        }

        if(XChange_SubTree(tree2)){
            DisplayBinaryTree(tree2);
            cout << endl;
        }
        else{
            cout << "是空树！" << endl;
        }

    }else{
        cout << "请先序输入二叉树1，以 # 为终端节点的结束。" << endl;
        Maual_CreateBinaryTree(tree1);
        cout << "请先序输入二叉树2" << endl;
        Maual_CreateBinaryTree(tree2);

        if(XChange_SubTree(tree1)){
            DisplayBinaryTree(tree1);
            cout << endl;
        }
        else{
            cout << "是空树！" << endl;
        }

        if(XChange_SubTree(tree2)){
            DisplayBinaryTree(tree2);
            cout << endl;
        }
        else{
            cout << "是空树！" << endl;
        }
    }
    return 0;
}

void Auto_CreateBinaryTree(BiTree &T,char Test[]){
    ch = Test[i++];
    if(ch == '#')
        T = NULL;
    else{
        T = new BiTNode;
        T -> data = ch;
        Auto_CreateBinaryTree(T -> lchild,Test);
        Auto_CreateBinaryTree(T -> rchild,Test);
    }
}

void Maual_CreateBinaryTree(BiTree &T){
    cin >> ch;
    if(ch == '#')
        T = NULL;
    else{
        T = new BiTNode;
        T -> data = ch;
        Maual_CreateBinaryTree(T -> lchild);
        Maual_CreateBinaryTree(T -> rchild);
    }
}

void DisplayBinaryTree(BiTree T){
    if(T){
        cout << T -> data;
        DisplayBinaryTree(T -> lchild);
        cout << "\"";
        DisplayBinaryTree(T -> rchild);
    }
}

/// @brief 将树的情况分四种，全空，不空，左空，右空，本质就是左右互换，判空只是减少temp使用。
/// @param T 数
/// @return  不为空成真赋值
bool XChange_SubTree(BiTree &T){
    BiTree temp;
    if(!T)
        return false;
    if(T ->lchild && T->rchild){
        temp = T -> lchild;
        T -> lchild = T -> rchild;
        T -> rchild = temp;
    }
    else if(T -> lchild == NULL && T -> rchild){
        T -> lchild = T -> rchild;
        T -> rchild = NULL;
    }
    else if(T -> lchild && T -> rchild == NULL ){
        T -> rchild = T -> lchild;
        T -> lchild = NULL;
    }
    XChange_SubTree(T -> lchild);
    XChange_SubTree(T -> rchild);
    return true;
}