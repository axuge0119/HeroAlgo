#pragma once
using namespace std;

///���ݽṹ�Ļ�������������+���ʣ����彲���Ǿ����ܸ�Ч�أ�����ɾ���ġ��飩 \
�����ͷ��ʵľ�����ʽ�����Ժͷ����� \
���ԣ�for/while ���� \
�����ԣ��ݹ� \

//1.����
void traverse(int arr[]) {
	int length = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; ++i) {
		//��������arr[i]
	}
}

//2.����
struct ListNode {
	int val;
	ListNode* next;
};

void traverse2(ListNode *head) {	//����
	for (ListNode* p = head; p != nullptr; p = p->next) {
		//��������p.val
	}
}

void traverse3(ListNode *head) {	//z�ݹ�
	//ǰ����� head->val
	traverse3(head->next);
	//�������� head->val
}


//3.�������������ǵ��͵ķ����Եݹ����
struct TreeNode {
	int val;
	TreeNode *left, *right;
};

void traverse4(TreeNode *root) {
	//ǰ����� root->val
	traverse4(root->left);
	//������� root->val
	traverse4(root->right);
	//������� root->val
}


//�ܽ᣺���ݽṹ�ǹ��ߣ��㷨��ͨ�����ʵĹ��߽���ض�����ķ��� \
���������������������˼ά�ģ��󲿷ֳ����㷨�����϶������ı������� \
�ر�أ����ݡ���̬�滮�����εȣ�ֻҪ�漰�ݹ�����⣬�����϶�����������





