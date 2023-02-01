#include <iostream>
#include <unordered_map>
using namespace std;

///˫ָ������ \
1.����ָ�룬���ڽ�����������⣬�����ж������Ƿ��л�\
2.����ָ�룬����������ַ�����������ֲ��ҵ�

//1����ָ���ж��������Ƿ��л�
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

//2��֪�л������ػ���ʼλ��
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

	return slow;  //����λ��
}

//3�����޻�������е�
ListNode* getMidPos(ListNode *head) {
	ListNode *fast, *slow;
	fast = slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;  //fast�ߵ�ͷ��slow���ߵ�һ��
}

//4���������е�����K��Ԫ��λ��
ListNode* getItemPos(ListNode *head, int k) {
	ListNode *fast, *slow;
	fast = slow = head;
	while (k-- > 0) {	//fast����k��
		fast = fast->next;
	}
	
	while (fast->next != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}


///����ָ��  ֻҪ���������Ӧ���뵽˫ָ��(�±�)����
//1.���ֲ���
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

	return -1; //δ�ҵ�
}

//2.����֮��
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

//3.��ת����
void reverse(int num[]) {
	int left = 0;
	int right = sizeof(num) / sizeof(num[0]) - 1;
	while (left < right) {
		swap(num[left], num[right]);
		left++;
		right--;
	}
}

//4.���������㷨  ### ˫ָ�뼼�ɵ���߾���  ###  �����ִ�����
//�㷨�Ĵ����߼�����\
  int left = 0, right = 0;
//while (right < s.size()) {
//	//���󴰿�
//	window.add(s[right]);
//	right++;
//
//	while (window needs shrink) {
//		window.remove(s[left]);
//		left++;
//	}
//}

//��������㷨������£�
void slidingWindow(string s, string t) {
	unordered_map<char, int> need, window;
	for (auto c : s) need[c]++;
}


