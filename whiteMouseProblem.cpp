#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
	int total = 5;														//总数量
	double posion_probability[5] = {0.1, 0.25, 0.25, 0.05, 0.35 };		//概率
	priority_queue<double, vector<double>, greater<double> > Q;			//优先队列并从小到大排序
	for (int i = 0; i < total; i++)
	{
		Q.push(posion_probability[i]);									//入队
	}
	double ans = 0;
	while (Q.size() > 2)							//只有最后两个元素的时候跳出，对应的就是根节点下的两个节点
	{
		double ta = Q.top();Q.pop();
		double tb = Q.top();Q.pop();
		ans += ta + tb;
		Q.push(ta + tb);							//将生成的新节点入队，并排序
	}
	
	ans += Q.top();Q.pop();							//将两个节点弹出并相加，最后得到根节点，也就是题目答案；
	ans += Q.top();Q.pop();

	cout.precision(2);								//输出格式控制；
	cout << ceil(ans);								//次数不存在小数次，必须向上取整

	return 0;
}