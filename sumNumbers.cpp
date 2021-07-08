
void travel(TreeNode* A,int sum,int &ans){
if(A==NULL) return;
sum=(sum*10)%1003;
sum=(sum+A->val)%1003;
if(A->left==NULL && A->right==NULL) {
    ans=(ans+sum)%1003; 
    return;
}
travel(A->right,sum,ans);
travel(A->left,sum,ans);
}
int Solution::sumNumbers(TreeNode* A) {
int sum=0,ans=0;
travel(A,sum,ans);
return ans%1003;
}
