// cppAlgo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "dynamic_programming.h"

using namespace std;
using namespace DynamicProgram;

int F[11];				//作为哈希表，存放各个状态
void init() {			//1.初始状态
	memset(F, -1, sizeof(F));
}
int Fact_dp(int n) {
	if (F[n] == -1) {	//2.确定状态转移方程
		F[n] = n > 0 ? Fact_dp(n - 1) * n : 1;	//3.执行状态转移
	}
	return F[n];	//4.求解最终解
}

//斐波那契数列
int f[50];
int fib(int n) {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[n] = f[n - 2] + f[n - 1];
	}

	return f[n];
}



//更改2
int main01()
{
    //std::cout << "Hello World!\n";

	/*int a = 3;
	int ans = DP::Fact(a);
	cout << ans << endl;*/

	//DP思想
	int a = 3;
	init();
	int ans2 = Fact_dp(a);


	system("pause");
	return 0;
}

//测试哈希表
int main() {
	vector<int> nums = { 1,2,4,21,2,6 };
	vector<int> ans = HashTable::findIndex(nums, 4);

	system("pause");
	return 0;
}

