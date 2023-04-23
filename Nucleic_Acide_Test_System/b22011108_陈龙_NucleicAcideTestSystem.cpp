#include <iostream>
#include <vector>
#include<stdlib.h>
#include <ctime>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//模拟病毒基因样本
#define ALPHA "t"
#define DELTA "s"
#define OMICRON "u"
#define ALPHA1 "op"
#define DELTA1 "f"
#define OMICRON1 "k"
string DNA[6] = {ALPHA,DELTA,OMICRON,ALPHA1,DELTA1,OMICRON1};

//试管基地址编号
long SingleTube = 1000360;
long MixedTube = 897000650;

//字符串比较使用
string man = "男";
string woman = "女";

//创建人员信息结构体
typedef struct{
    string Number;          //人员编号
    string Name;            //姓名
    string Gender;          //性别
    int Age;                //年龄
    string Phone;           //手机号
    int TestWay;            //测试方式：0混管 1单管
    int Statues;            //核酸结果状态
    long TubeNumber;        //核酸试管编号
    string Covid_squeue;    //检测出的基因序列编号
}Personal_Info;

//人员顺序表
typedef struct {
    Personal_Info *element;
    int length;
}PersonSql;

//核算队伍,使用队列
vector<string> SingleTestQue;   //单人单管
vector<string> MixedTestQue;    //十人混管

bool Init_List(PersonSql &L);                       //初始化线性表
bool Insert_List(PersonSql &L, int i, string num);  //插入顺序表
bool Drop_List(PersonSql &L, string num);           //删除元素
bool Alter_List(PersonSql &L, string num);          //修改元素
int Find_PersonInfo(PersonSql L, string number);    //查找人员信息
string Get_NucleicSquence(int len);                 //伪随机获取序列
int GetPersonPosition(PersonSql L, string number);  //获取元素所在位置
void Seperate_Queue(PersonSql &L,int i);            //将人员按核酸方式分开
void NucleiTest(PersonSql &L, int i);               //测试方法
void SingleTest(PersonSql &L);                      //单人测试
void MixedTest(PersonSql &L);                       //混合测试
void Displaymenue(int amount);                      //显示菜单

int main(){
    int amount = 0;             //已登记核酸人数
    int choice = 0;             //模式选择
    string temp;                //临时数据空间
    int temp_j = 0;             //计数器
    bool flag  = false;         //核酸检测标志
    string str_address1;        //住址，楼号
    string str_address2;        //住址，房间号

    PersonSql Person_List;      //人员信息表

    Init_List(Person_List);     //初始化

    system("cls");              //刷新界面

    Displaymenue(amount);       //展示菜单

    while(cin >> choice){
        switch (choice){
            case 1:
                system("cls");
                cout << "请输入人员信息：编号，姓名，性别，年龄，手机号，测试方式" << endl;
                cout << "10位编号格式：xxxyyyyzzA" << endl;
                cout << "编号格式：楼号(三位)+房间号(四位)+人员顺序号(二位)+采样方式（0为单人单管，1为混采）" << endl;
                cout << "如：0010101011" << endl;
                while (cin >> temp)
                {
                    if(temp == "-1"){
                        system("cls");
                        Displaymenue(amount);
                        break;
                    }
                    else{
                        if(temp.length() == 0 || temp.length() > 10){
                            cout <<  endl << "您输入的编号有误，请重试！"<<endl;
                            continue;
                        }
                        if(GetPersonPosition(Person_List,temp) != -1){
                            cout <<  endl << "人员编号已存在！请重新输入！"<<endl;
                        }else{
                        if (Insert_List(Person_List, amount, temp)){
                                cout <<  endl << "信息录入成功！" << endl;
                                ++amount;
                                cout <<  endl << "是否继续输入？ 继续 : 输入人员编号 结束 : -1" << endl;
                            }
                            else{
                                cout <<  endl << "插入失败，请重启本程序再次尝试！" << endl;
                            } 
                        }
                    }
                }
                system("cls");
                Displaymenue(amount);
                break;
            case 2:
                system("cls");
                cout << "请输入查询人员编号：" << endl;
                cin >> temp;
                while (temp != "-1"){
                    Find_PersonInfo(Person_List,temp);
                    cout <<  endl << "是否继续查询？ 继续 : 输入人员编号 、 结束 : -1" << endl;
                    cin >> temp;
                }
                system("cls");
                Displaymenue(amount);
                break;
            case 3:
                system("cls");
                cout << "请输入要修改的人员编号：" << endl;
                cin >> temp;
                while (temp != "-1"){
                    if(Alter_List(Person_List,temp))
                        cout <<  endl << "修改成功！" << endl;
                    else
                        cout <<  endl << "修改失败！" << endl;
                    cout <<  endl << "是否继续修改？ 继续 : 输入人员编号 、 结束 : -1" << endl;
                    cin >> temp;
                }
                system("cls");
                Displaymenue(amount);
                break;
            case 4:
                system("cls");
                cout << "请输入要删除的人员编号：" << endl;
                cin >> temp;
                while (temp != "-1"){
                    if(Drop_List(Person_List,temp)){
                        cout << "删除成功！" << endl;
                        --amount;
                    }
                    else
                        cout << "删除失败！" << endl;
                    cout <<  endl << "是否继续删除？ 继续 : 输入人员编号 、 结束 : -1" << endl;
                    cin >> temp;
                }
                system("cls");
                Displaymenue(amount);
                break;
            case 5:
                system("cls");
                if(amount == 0){
                    cout << "当前无任何核酸人员！" << endl;
                    system("pause");
                    system("cls");
                    Displaymenue(amount);
                    break;
                }
                else{
                    cout << "当前待核酸人数为： " << amount << endl;
                    cout << "即将开始全自动核酸模式 ··· ···" << endl;
                    Seperate_Queue(Person_List,amount);
                    cout <<  endl << "当前单人单管人数为："<<SingleTestQue.size()
                    <<"    当前混管人数为："<<MixedTestQue.size()<<endl;
                    SingleTest(Person_List);
                    MixedTest(Person_List); 
                    cout << "检测结束！"<<endl;
                    flag = true;
                }
                system("pause");
                system("cls");
                Displaymenue(amount);
                break;

            case 6:
                system("cls");
                if(!flag){
                    cout << "暂未做核酸！无数据！" << endl;
                    system("pause");
                    system("cls");
                    Displaymenue(amount);
                    break;
                }
                cout << "正在查询，请稍后..." << endl;
                for(int i = 0; i < Person_List.length; i++){
                    if(Person_List.element[i].Statues == 1){
                        str_address1 = Person_List.element[i].Number.substr(0,3) + "号";
                        str_address2 = Person_List.element[i].Number.substr(3,4) + "室";
                        cout << Person_List.element[i].Number << "  "
                            << Person_List.element[i].Name<<"住址 ： " << str_address1 <<
                            str_address2<< "   |  为核酸异常人员！请尽快隔离观察！"<<endl;
                            ++temp_j;
                    }
                }
                if(temp_j == 0){
                    cout << " 本小区一切正常！" << endl << "待花开，春依旧" << endl << "人归来，仍年少" << endl;
                }
                system("pause");
                system("cls");
                Displaymenue(amount);
                break;
            case 7:
                system("cls");
                cout << "当前样本有：" << endl <<"ALPHA : " << ALPHA  << endl;
                cout << "DELTA : " << DELTA << endl;
                cout << "OMICRON : " << OMICRON << endl;
                cout << "ALPHA1 : " << ALPHA1 << endl;
                cout << "DELTA1 : " << DELTA1  << endl;
                cout << "OMICRON1 : " << OMICRON1 << endl;
                system("pause");
                system("cls");
                Displaymenue(amount);
                break;

            case 8:
                system("cls");
                cout << "恭喜你！已经掌握了上班的精髓，只有摸鱼才赚老板钱！" << endl;
                cout << "只有摸鱼才是给自己创造价值！！" << endl;
                cout << "年轻人，带着摸鱼的精神走向职场吧！" << endl;
                return 0;
            default:
            system("pause");
            return 0;
        }
    }
    return 0;
}


//初始化人员表
bool Init_List(PersonSql &L){
    L.element = new Personal_Info [1005];
    if(!L.element)
        return false;
    L.length = 0;
    return true;
}

//插入信息
bool Insert_List(PersonSql &L, int i, string num){
    if(i < 0 || i > L.length + 1){
        cout << "位置信息不合法！" <<endl;
        return false;
    }
    if(L.length == 1000){
        cout << "今日核酸人数已达上限！" <<endl;
        return false;
    }
    L.element[i].Number = num;
    cin >> L.element[i].Name;
    while(cin >> L.element[i].Gender){
        if((L.element[i].Gender == man) || (L.element[i].Gender == woman)){
            break;
        }
        else{
            cout <<  "性别输入有误，请重试！" <<endl;
        }
    }
    while (cin >> L.element[i].Age){
        if(L.element[i].Age > 150 || L.element[i].Age < 0 ){
            cout <<  "年龄输入有误，请重试！" <<endl;
        }
        else{
            break;
        }
    }
    while(cin >> L.element[i].Phone){
        if(L.element[i].Phone.length() != 11){
            cout <<  "输入手机号有误，请检查是否为11位手机号！" <<endl;
        }else{
            break;
        }
    }
    while(cin >> L.element[i].TestWay){
        if(L.element[i].TestWay == 0 || L.element[i].TestWay == 1){
            break;
        }else{
            cout <<  "核酸方式有误，请重试！" <<endl;
        }
    }
    L.element[i].Statues = 3;
    ++L.length;
    return true;
}
//删除人员信息
bool Drop_List(PersonSql &L, string num){
    int i = GetPersonPosition(L,num);
    if (i == -1){
        cout << "人员信息未检测到，请重试！"<< endl;
        return false;
    }
    if(i == L.length -1){               //最后一个元素
        L.element[i].Number = "0";
        L.element[i].Name = "0";
        L.element[i].Age = 0;
        L.element[i].Gender = "0";
        L.element[i].Phone = "0";
        L.element[i].TestWay = 0;
        L.element[i].TubeNumber = 0;
        L.element[i].Covid_squeue = "0";
        L.element[i].Statues = 0;
        return true;
    }
    for(int j = i; j < L.length; j++){ //非最后一个元素；
        L.element[j].Number = L.element[j+1].Number;
        L.element[j].Name = L.element[j+1].Name;
        L.element[j].Age = L.element[j+1].Age;
        L.element[j].Phone = L.element[j+1].Phone;
        L.element[j].Gender = L.element[j+1].Gender;
        L.element[j].Statues = L.element[j+1].Statues;
        L.element[j].TestWay = L.element[j+1].TestWay;
        L.element[j].TubeNumber = L.element[j+1].TubeNumber;
        L.element[j].Covid_squeue = L.element[j+1].Covid_squeue;
    }
    --L.length;
    return true;
}

//修改人员信息           
bool Alter_List(PersonSql &L, string num){
    int i = GetPersonPosition(L,num);
    if (i == -1){
        cout << "人员信息未检测到，请重试！"<< endl;
        return false;
    }
    cout << "请输入全部信息，包括编号" << endl;
    while(cin >> L.element[i].Number){
        if(L.element[i].Number.length() == 10 )
            break;
        else
            cout <<  "编号不合规，请重试！" <<endl;
    }
    cin >> L.element[i].Name;
    while(cin >> L.element[i].Gender){
        if((L.element[i].Gender == man) || (L.element[i].Gender == woman))
            break;
        else
            cout <<  "性别输入有误，请重试！" <<endl;
    }
    while (cin >> L.element[i].Age){
        if(L.element[i].Age > 150 || L.element[i].Age < 0 )
            cout <<  "年龄输入有误，请重试！" <<endl;
        else
            break;
    }
    while(cin >> L.element[i].Phone){
        if(L.element[i].Phone.length() == 11)
            break;
        else
            cout <<  "输入手机号有误，请检查是否为11位手机号！" <<endl;
    }
    while(cin >> L.element[i].TestWay){
        if(L.element[i].TestWay == 0 || L.element[i].TestWay == 1)
            break;
        else
            cout <<  "核酸方式有误，请重试！" <<endl;
    }
    L.element[i].Statues = 3;
}         


//查找信息
int Find_PersonInfo(PersonSql L, string number){
    if(L.length == 0){
        cout << "当前无任何信息，查询无效！"<<endl;
        return -1;
    }
    int i = GetPersonPosition(L,number);
    if(i != -1){
        cout << "编号 ："<<L.element[i].Number << endl;
            cout << "|  性名 ：" << L.element[i].Name;
            cout << "|  性别 ：" << L.element[i].Gender;
            cout << "|  年龄 ：" << L.element[i].Age;
            cout << "|  手机号 ：" << L.element[i].Phone << endl;
            if (L.element->TestWay == 1){
                cout << "|  测试方式 ：混管检测" << endl << endl;
            }
            else{
                cout << "测试方式 ：单人单管检测";
            }
            if(L.element[i].Statues != 3){
                cout << "|  核酸管编号 ：" << L.element[i].TubeNumber;
                cout << "|  核酸序列 ：" << L.element[i].Covid_squeue << endl;
            }else{
                cout << "暂未核酸！无核酸数据！" << endl;
            }
            return i;
    }else{
        cout << "没有查询到该人员信息，请检查人员信息后再重试" << endl;
        return 0;
    }
    
}

string Get_NucleicSquence(int len){
    string str;
    char c;
    int idx;
    for(idx = 0;idx < len;idx ++){
        c = 'a' + rand()%26;
        str.push_back(c);
    }
    return str;
}

//获取人员在信息表中的编号
int GetPersonPosition(PersonSql L, string number){
    for (int i = 0; i < L.length; i++){
        if(number == L.element[i].Number){
            return i;
        }
    }
    return -1;
}

//采样分队
void Seperate_Queue(PersonSql &L,int i){
    for(int k = 0; k < i; k++){
        if(L.element[k].TestWay == 1)
            SingleTestQue.push_back(L.element[k].Number);
        else
            MixedTestQue.push_back(L.element[k].Number);
    }
}

//检测方法
void NucleiTest(PersonSql &L, int i){
    string::size_type idx;
    for(int i = 0; i < 6; i++){
    	idx = L.element[i].Covid_squeue.find(DNA[i]);
    	if(idx != string::npos){
    		L.element[i].Statues = 1;       //中招，核酸有问题
    		return;
		}
	}
	L.element[i].Statues = 2;       //安全，没有问题
}

//采样检测
//单管检测
void SingleTest(PersonSql &L){
    int position = 0;
    while (SingleTestQue.size()){
        position = GetPersonPosition(L,SingleTestQue.back());
        if(position != -1){
            L.element[position].TubeNumber = SingleTube;
            L.element[position].Covid_squeue = Get_NucleicSquence(10);
            NucleiTest(L,position);
            SingleTestQue.pop_back();
            Sleep(300);
            ++SingleTube;
            cout << "当前单管人数为 ： " << SingleTestQue.size()+1 << "  |  核酸试管编号为 ： " << SingleTube << endl;
        }
    }
    
}

//混管检测
void MixedTest(PersonSql &L){
    int position = 0;
    int count = 0;
    while (MixedTestQue.size()){
        position = GetPersonPosition(L,MixedTestQue.back());
        if(position != -1){
            L.element[position].TubeNumber = MixedTube;
            L.element[position].Covid_squeue = Get_NucleicSquence(10);
            MixedTestQue.pop_back();
            NucleiTest(L,position);
            ++count;
            if(count % 10 == 0){
                ++MixedTube;
            }
            Sleep(300);
            cout << "当前混管人数为 ： " << MixedTestQue.size()+1 << "  |  核酸试管编号为 ： " << MixedTube << endl;
        }
    }
}

//显示菜单
void Displaymenue(int amount){
    cout << "***************************************************" << endl;
    cout << "***            欢迎使用核酸系统                 ***" << endl;
    cout << "***            核酸点编号:B22011108             ***" << endl;
    cout << "***            今日已核酸人数:" << amount << "                 ***" << endl;
    cout << "***            请选择您要执行的操作             ***" << endl;
    cout << "***            1 . 插入人员信息                 ***" << endl;
    cout << "***            2 . 查询人员信息                 ***" << endl;
    cout << "***            3 . 修改人员信息                 ***" << endl;
    cout << "***            4 . 删除人员信息                 ***" << endl;
    cout << "***            5 . 开始核酸检测                 ***" << endl;
    cout << "***            6 . 查询风险人员                 ***" << endl;
    cout << "***            7 . 查看病毒样本                 ***" << endl;
    cout << "***            8 . 我就上班摸鱼看看，退出系统   ***" << endl;
    cout << "***************************************************" << endl;
}
