/******************************************************************/
/*     作者 ： 陈龙                                                */
/*     程序 ： 两个二叉树是否相等                                   */
/*     测试用例：                                                  */
/*            ABC##DE#G##F### && ABC##DE#G##F###                  */
/*            ACB##DE#G##F### && ABC##DE#G##F###                  */
/*                                                                */
/*     输出 :                                                     */
/*            是 否                                               */
/*     函数说明                                                   */
/*            Auto_CreateBinaryTree 自动生成树                    */
/*            Manual_CreateBinaryTree 手动生成树                  */
/*            Is_SameTree           判断是否是一棵树               */
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
bool Is_SameTree(BiTree A, BiTree B);

int main(){
    int Test_Mode = 0;                             //测试模式
    BiTree tree1, tree2, tree3;
    cout << "请输入测试模式，1为自动测试，0为手动输入" << endl;

    cin >> Test_Mode;

    if(Test_Mode == 1){
        Auto_CreateBinaryTree(tree1,Test_One);
        i = 0;                                  //下标清零，不然数组会越界报错;
        Auto_CreateBinaryTree(tree2,Test_One);
        i = 0;
        Auto_CreateBinaryTree(tree3,Test_Two);
        i = 0;

        if(Is_SameTree(tree1,tree2)){
            DisplayBinaryTree(tree1);cout << "和";DisplayBinaryTree(tree2);
            cout << "是同一颗二叉树" << endl;
        }else{
            DisplayBinaryTree(tree1);cout << "和"; DisplayBinaryTree(tree2);
            cout << "不是同一颗二叉树" << endl;
        }

        if(Is_SameTree(tree1,tree3)){
            DisplayBinaryTree(tree1);cout << "和"; DisplayBinaryTree(tree3);
            cout << "是同一颗二叉树" << endl;
        }else{
            DisplayBinaryTree(tree1);cout << "和";DisplayBinaryTree(tree3);
            cout << "不是同一颗二叉树" << endl;
        }

    }else{
        cout << "请先序输入二叉树1，以 # 为终端节点的结束。" << endl;
        Maual_CreateBinaryTree(tree1);
        cout << "请先序输入二叉树2" << endl;
        Maual_CreateBinaryTree(tree2);
        cout << "请先序输入二叉树3" << endl;
        Maual_CreateBinaryTree(tree3);

        if(Is_SameTree(tree1,tree2)){
            DisplayBinaryTree(tree1);cout << "和";DisplayBinaryTree(tree2);
            cout << "是同一颗二叉树" << endl;
        }else{
            DisplayBinaryTree(tree1);cout << "和"; DisplayBinaryTree(tree2);
            cout << "不是同一颗二叉树" << endl;
        }

        if(Is_SameTree(tree1,tree3)){
            DisplayBinaryTree(tree1);cout << "和"; DisplayBinaryTree(tree3);
            cout << "是同一颗二叉树" << endl;
        }else{
            DisplayBinaryTree(tree1);cout << "和";DisplayBinaryTree(tree3);
            cout << "不是同一颗二叉树" << endl;
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

bool Is_SameTree(BiTree A, BiTree B){
    if(A == NULL && B == NULL)
        return true;            //空树和空树相等
    if(A == NULL || B == NULL)
        return false;           //空树和非空树肯定不相等
    if(A -> data != B -> data)
        return false;           //元素不同不是一个二叉树
    return (Is_SameTree(A -> lchild, B -> lchild) && Is_SameTree(A -> rchild, B -> rchild));//递归左右子树比较
}