#include <bits/stdc++.h>
using namespace std;
struct Node
{
 int key;
 struct Node *left, *right;
struct Node *newNode(int item)
{
 struct Node *temp = new Node;
 temp->key = item;
 temp->left = temp->right = NULL;
 return temp;
}
void preorder(Node *root)
{
 if (root != NULL)
 {
	 printf("%d ", root->key);
	 preorder(root->left);
	 preorder(root->right);
 }
}
vector<Node *> getTrees(int arr[], int start, int end)
{
 vector<Node *> trees;
 if (start > end)
 {
	 trees.push_back(NULL);
	 return trees;
 }
 for (int i = start; i <= end; i++)
 {
	 vector<Node *> ltrees = getTrees(arr, start, i-1);
	 vector<Node *> rtrees = getTrees(arr, i+1, end);
	 {
		 for (int k = 0; k < rtrees.size(); k++)
		 {
			 Node * node = newNode(arr[i]);
			 node->left = ltrees[j];
			 node->right = rtrees[k];
			 trees.push_back(node);
		 }
	 }
 }
 return trees;
}
int main()
{
 int in[] = {4, 5, 7};
 int n = sizeof(in) / sizeof(in[0]);

 vector<Node *> trees = getTrees(in, 0, n-1);

 cout << "Preorder traversals of different "
		 << "possible Binary Trees are \n";
 for (int i = 0; i < trees.size(); i++)
 {
	 preorder(trees[i]);
	 printf("\n");
 }
 return 0;
}
