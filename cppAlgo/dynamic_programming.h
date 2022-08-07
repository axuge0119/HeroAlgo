#pragma once
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
//求解动态规划问题
namespace DynamicProgram {
	//1.什么是DP? 
	//一种递归思想
	//本质是空间换时间
	//解题方法：设计状态转移图,有向无环图

	//2.解题步骤：状态可以存储到哈希表中，即可快速访问和赋值，从而加速下一个状态的求解
	//a.设计状态
	//b.确定状态转移方程
	//c.确定初始状态
	//d.执行状态转移
	//e.计算最终解

	//3.判断一个问题是搜索还是动态规划：将节点抽象，关系用边表示，用人脑简单求一次拓扑排序（有向无环图才有拓扑排序）


	//拓展：如何写出拓扑排序：选出一个没有前驱的节点作为输入
	class DP
	{
		int f[50];
	public:
		//最简单的DP: 阶乘
		//直接使用递归思想：
		static int Fact(int n) {
			return n > 0 ? Fact(n - 1)*n : 1;
		}
		//===> 使用DP思想
		/** 此段只为展示思路完整性
		int F[11];				//作为哈希表，存放各个状态
		void init() {
			memset(F, -1, sizeof(F));
		}
		static int Fact_dp(int n) {
			if (F[n] != -1) {	//
				F[n] = n > 0 ? Fact_dp(n - 1) * n : 1;
			}
			return F[n];
		}
		*/

	//..
	};


	//查找N个数字组合方式满足与目标值关系的下标
	class HashTable {
	public:
		//暴力枚举
		static vector<int> findIndex(vector<int> &nums, int target) 
		{
			int n = nums.size();
			for (int i = 0; i < n; ++i)
			{
				for (int j = i + 1; j < n; ++j) {
					if (nums[i] + nums[j] == target)
						return { i,j };
				}
			}
			return {};
		}
		//二分查找
		static bool binFind(vector<int> &nums, int l, int r, int val){ //确认是否能找到
			while (l < r) {
				int mid = (l + r) >> 2;
				if (val == nums[mid])
					return true;
				else if (nums[mid] > val)
					r = mid - 1;
				else
					l = mid + 1;
			}
			return false;
		}
		//
		static int linearFind(vector<int> nums, int l, int r, int val) { //在原数组中查找
			int n = nums.size();
			for (int i = 0; i < n; ++i) {
				if (val == nums[i])
					return i;
			}
			return -1;
		}
		static vector<int> twoSum(vector<int> &nums, int target) {
			vector<int> sortedNums(nums);
			sort(sortedNums.begin(), sortedNums.end());
			int n = nums.size();
			int x = 0;				//缓存数组中的某一元素值
			for (int i = 1; i < n; ++i) {	//先找到x
				x = sortedNums[i];
				if (binFind(sortedNums, i + 1, n - 1, target - x)) {  
					break;
				}
			}
			int a = linearFind(nums, 0, n - 1, x);
			int b = linearFind(nums, a + 1, n - 1, target - x);
			if (b == -1)
				b = linearFind(nums, 0, a - 1, target - x);
			return { a,b };
		}

		static vector<int> twoSumEx(vector<int> &nums, int target) {
			//map<int, int> has;		  //元素作key, 下标作val
			unordered_map<int, int> has;  //注意：map的底层是红黑树，增删改查的时间复杂度O(logN)；unordered_map底层为哈希表，时间复杂度O(1)
			int n = nums.size();
			for (int i = n-1; i >= 0; --i) {
				if (has.find(target - nums[i]) != has.end()) {
					return { has[target - nums[i]],i };			//存在该元素
				}
				has[nums[i]] = i;	//缓存原数组元素
			}
			return {};
		}

		static vector<>
	};


}
