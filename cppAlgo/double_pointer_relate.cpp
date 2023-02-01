#include <iostream>
#include <unordered_map>
using namespace std;

///双指针问题 \
1.快慢指针，用于解决链表中问题，例如判定链中是否有环\
2.左右指针，用于数组和字符串，例如二分查找等

//1快慢指针判定链表中是否有环
#include "base_datastructure.h"
bool hasCycle(ListNode *head) {
	ListNode *fast, *slow;
	fast = slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		fast = fast->next->next;
		slow = fast->next;
		if (fast == slow)
			return true;
	}

	return false;
}

//2已知有环，返回环开始位置
ListNode* detectCycle(ListNode *head) {
	ListNode *fast, *slow;
	fast = slow = head;
	while (fast->next != nullptr && fast->next->next != nullptr) {
		fast = fast->next->next;
		slow = fast->next;
		if (fast == slow) break;
	}

	slow = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;  //相遇位置
}

//3返回无环链表的中点
ListNode* getMidPos(ListNode *head) {
	ListNode *fast, *slow;
	fast = slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;  //fast走到头则slow刚走到一半
}

//4返回链表中倒数第K个元素位置
ListNode* getItemPos(ListNode *head, int k) {
	ListNode *fast, *slow;
	fast = slow = head;
	while (k-- > 0) {	//fast先走k步
		fast = fast->next;
	}
	
	while (fast->next != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}


///左右指针  只要数组有序就应该想到双指针(下标)技巧
//1.二分查找
int binarySearch(int num[], int target) {
	int left = 0;
	int right = sizeof(num) / sizeof(num[0]) - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (num[mid] == target)
			return mid;
		else if (num[mid] > target) {
			right = mid - 1;
		}
		else if (num[mid] < target) {
			left = mid + 1;
		}
	}

	return -1; //未找到
}

//2.两数之和
int* TwoSum(int num[], int target, int &left, int &right) {
	int index[2];
	left = 0;
	right = sizeof(num) / sizeof(num[0]) - 1;
	while (left < right) {
		int sum = num[left] + num[right];
		if (sum == target)
			return new int[] {left + 1, right + 1};
		else if (sum > target)
			right--;
		else if (sum < target)
			left++;
	}

	return new int[] {-1, -1};
}

//3.反转数组
void reverse(int num[]) {
	int left = 0;
	int right = sizeof(num) / sizeof(num[0]) - 1;
	while (left < right) {
		swap(num[left], num[right]);
		left++;
		right--;
	}
}

//4.滑动窗口算法  ### 双指针技巧的最高境界  ###  处理字串问题
//算法的大致逻辑如下\
  int left = 0, right = 0;
//while (right < s.size()) {
//	//增大窗口
//	window.add(s[right]);
//	right++;
//
//	while (window needs shrink) {
//		window.remove(s[left]);
//		left++;
//	}
//}

//更具体地算法框架如下：
void slidingWindow(string s, string t) {
	unordered_map<char, int> need, window;
	for (auto c : s) need[c]++;
}


