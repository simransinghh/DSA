int minno = -1;
bool once = false;
int Solution::kthsmallest(TreeNode* A, int B) {
    if(A==NULL) return -1;
    if(A->left==NULL && A->right==NULL && !once){
        once = true;
        minno = 1;
        if(B==1) return A->val;
        return -1;
    }
    int a = kthsmallest(A->left,B);
    minno++;
    if(minno==B) return A->val;
    int b = kthsmallest(A->right,B);
    if(a != -1) return a;
    else return b;
}
