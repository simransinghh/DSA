bool isBST(node*root, int minRange = INT_MIN, int maxRange = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	bool leftBST = isBST(root->left, minRange, root->data);
	bool rightBST = isBST(root->right, root->data, maxRange);

	if (leftBST and rightBST and root->data > minRange and root->data < maxRange) {
		return true;
	} else {
		return false;
	}
}
