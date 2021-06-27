void push(Node** tail_ref, Node* node)
{
	if (*tail_ref == NULL)
	{
		*tail_ref = node;
		node->left = node->middle = node->right = NULL;

		return;
	}
	(*tail_ref)->right = node;
	node->left = (*tail_ref);
	node->right = node->middle = NULL;
	(*tail_ref) = node;
}
Node* TernaryTreeToList(Node* root, Node** head_ref)
{
	// Base case
	if (root == NULL)
		return NULL;
	static Node* tail = NULL;
	Node* left = root->left;
	Node* middle = root->middle;
	Node* right = root->right;
	if (*head_ref == NULL)
		*head_ref = root;
	push(&tail, root);
	TernaryTreeToList(left, head_ref);
	TernaryTreeToList(middle, head_ref);
	TernaryTreeToList(right, head_ref);
}

}
