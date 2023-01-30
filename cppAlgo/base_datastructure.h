#pragma once
using namespace std;

///数据结构的基本操作：遍历+访问：具体讲就是尽可能高效地（增、删、改、查） \
遍历和访问的具体形式：线性和非线性 \
线性：for/while 迭代 \
非线性：递归 \

//1.数组
void traverse(int arr[]) {
	int length = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; ++i) {
		//迭代访问arr[i]
	}
}

//2.链表
struct ListNode {
	int val;
	ListNode* next;
};

void traverse2(ListNode *head) {	//迭代
	for (ListNode* p = head; p != nullptr; p = p->next) {
		//迭代遍历p.val
	}
}

void traverse3(ListNode *head) {	//z递归
	//前序遍历 head->val
	traverse3(head->next);
	//后续遍历 head->val
}


//3.二叉树遍历就是典型的非线性递归遍历
struct TreeNode {
	int val;
	TreeNode *left, *right;
};

void traverse4(TreeNode *root) {
	//前序遍历 root->val
	traverse4(root->left);
	//中序遍历 root->val
	traverse4(root->right);
	//后序遍历 root->val
}


//总结：数据结构是工具，算法是通过合适的工具解决特定问题的方法 \
二叉树是最容易培养框架思维的，大部分常考算法本质上都是树的遍历问题 \
特别地，回溯、动态规划、分治等，只要涉及递归的问题，基本上都是树的问题





