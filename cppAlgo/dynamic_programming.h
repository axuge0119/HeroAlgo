#pragma once
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
//��⶯̬�滮����
namespace DynamicProgram {
	//1.ʲô��DP? 
	//һ�ֵݹ�˼��
	//�����ǿռ任ʱ��
	//���ⷽ�������״̬ת��ͼ,�����޻�ͼ

	//2.���ⲽ�裺״̬���Դ洢����ϣ���У����ɿ��ٷ��ʺ͸�ֵ���Ӷ�������һ��״̬�����
	//a.���״̬
	//b.ȷ��״̬ת�Ʒ���
	//c.ȷ����ʼ״̬
	//d.ִ��״̬ת��
	//e.�������ս�

	//3.�ж�һ���������������Ƕ�̬�滮�����ڵ���󣬹�ϵ�ñ߱�ʾ�������Լ���һ���������������޻�ͼ������������


	//��չ�����д����������ѡ��һ��û��ǰ���Ľڵ���Ϊ����
	class DP
	{
		int f[50];
	public:
		//��򵥵�DP: �׳�
		//ֱ��ʹ�õݹ�˼�룺
		static int Fact(int n) {
			return n > 0 ? Fact(n - 1)*n : 1;
		}
		//===> ʹ��DP˼��
		/** �˶�ֻΪչʾ˼·������
		int F[11];				//��Ϊ��ϣ����Ÿ���״̬
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


	//����N��������Ϸ�ʽ������Ŀ��ֵ��ϵ���±�
	class HashTable {
	public:
		//����ö��
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
		//���ֲ���
		static bool binFind(vector<int> &nums, int l, int r, int val){ //ȷ���Ƿ����ҵ�
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
		static int linearFind(vector<int> nums, int l, int r, int val) { //��ԭ�����в���
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
			int x = 0;				//���������е�ĳһԪ��ֵ
			for (int i = 1; i < n; ++i) {	//���ҵ�x
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
			//map<int, int> has;		  //Ԫ����key, �±���val
			unordered_map<int, int> has;  //ע�⣺map�ĵײ��Ǻ��������ɾ�Ĳ��ʱ�临�Ӷ�O(logN)��unordered_map�ײ�Ϊ��ϣ��ʱ�临�Ӷ�O(1)
			int n = nums.size();
			for (int i = n-1; i >= 0; --i) {
				if (has.find(target - nums[i]) != has.end()) {
					return { has[target - nums[i]],i };			//���ڸ�Ԫ��
				}
				has[nums[i]] = i;	//����ԭ����Ԫ��
			}
			return {};
		}

		static vector<>
	};


}
