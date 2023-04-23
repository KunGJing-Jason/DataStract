```C++
ADT 人员信息表{
    数据对象：D = {Person(string Number;     //人员编号
                    string Name;            //姓名
                    string Gender;          //性别
                    int Age;                //年龄
                    string Phone;           //手机号
                    int TestWay;            //测试方式
                    int Statues;            //核酸结果
                    long TubeNumber;        //试管编号
                    string Covid_squeue;    //基因序列
                ) }
    数据关系：R = {All Elements ∈ Person_Self}
    基本操作：
        bool Init_List(PersonSql &L);                       //初始化线性表
        bool Insert_List(PersonSql &L, int i, string num);  //插入元素
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
}ADT List

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

bool Init_List(PersonSql &L){                       //初始化线性表
    申请空间，大小:1005;
    若(申请失败)
        返回 false;
    设置表长为0;
    返回 true;
}
bool Insert_List(PersonSql &L, int i, string num){  //插入元素
    若(位置 < 0 或 位置 + 1 > 表长)
        返回 false;
    若(表长已经为最大表长)
        返回 false;
    成员i.编号 = num;
    输入成员i的其他信息,并检查信息是否合法;
    返回 true;
}
bool Drop_List(PersonSql &L, string num){          //删除元素
    若(num不存在于表中)
        返回 false;
    将后续所有元素前移;
    --表长;
    返回 true;
}
bool Alter_List(PersonSql &L, string num){          //修改元素
    若(num不存在于表中)
        返回 false;
    输入新信息，并对信息检查，合法则重新赋值;
}
int Find_PersonInfo(PersonSql L,string number){    //查找人员信息
    调用GetPersonPosition()方法;
    若无信息，则返回-1;
    输出结果;
    循环结束，返回 1;
}
string Get_NucleicSquence(int len){                 //伪随机获取序列
    循环十次:
        通过rand()%26，取得一个 0 - 25的数字，赋值给 x ;
        c = 'a' + x; 
        将字符推入字符串
    循环结束，返回 字符串;
}

int GetPersonPosition(PersonSql L,string number){ //获取元素所在位置
    循环表长度次数:
        若(num不存在表中)
            返回 -1;
    循环结束，返回位置信息;
}
void Seperate_Queue(PersonSql &L,inti){            //将人员按核酸方
    循环i次:
        若(元素i的检测方式为0)
            入混合检测队伍;
        否则
            进入单人单管队伍;
}式分开
void NucleiTest(PersonSql &L, inti){               //测试方法
    若(元素i的序列含样本){
        元素i.状态为1;
        返回;
    }
    元素i.状态为2;
}
void SingleTest(PersonSql L){                     //单人测试
    当(单人检测队伍不为空时)
        执行:
        获取元素位置;
        若位置合法
            获取核酸管编号;
            获取序列;
            检测序列;
            出队;
            核酸管编号++;
}
void MixedTest(PersonSql L){                       //混合测试
     当(单人检测队伍不为空时)
        执行:
        获取元素位置;
        若位置合法
            获取核酸管编号;
            获取序列;
            检测序列;
            出队;
            若已检测10人
                核酸管编号++;
}
void Displaymenue(int amount){                      //显示菜单
    显示菜单信息;
}