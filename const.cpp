// C++ program to create a Complete Binary tree from its Linked List
// Representation
#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Linked list node
struct ListNode
{
	int data;
	ListNode* next;
};

// Binary tree node structure
struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left, *right;
};

// Function to insert a node at the beginning of the Linked List
void push(struct ListNode** head_ref, int new_data)
{
	// allocate node and assign data
	struct ListNode* new_node = new ListNode;
	new_node->data = new_data;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// move the head to point to the new node
	(*head_ref) = new_node;
}

// method to create a new binary tree node from the given data
BinaryTreeNode* newBinaryTreeNode(int data)
{
	BinaryTreeNode *temp = new BinaryTreeNode;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void convertList2Binary(ListNode *head, BinaryTreeNode* &root)
{
	queue<BinaryTreeNode *> q;

	// Base Case
	if (head == NULL)
	{
		root = NULL; 
		return;
	}
	root = newBinaryTreeNode(head->data);
	q.push(root);
	head = head->next;
	while (head)
	{
		BinaryTreeNode* parent = q.front();
		q.pop();
		BinaryTreeNode *leftChild = NULL, *rightChild = NULL;
		leftChild = newBinaryTreeNode(head->data);
		q.push(leftChild);
		head = head->next;
		if (head)
		{
			rightChild = newBinaryTreeNode(head->data);
			q.push(rightChild);
			head = head->next;
		}
		parent->left = leftChild;
		parent->right = rightChild;
	}
}

void inorderTraversal(BinaryTreeNode* root)
{
	if (root)
	{
		inorderTraversal( root->left );
		cout << root->data << " ";
		inorderTraversal( root->right );
	}
}
