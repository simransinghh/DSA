unordered_map<int,int> idxinin; 
TreeNode* prein(vector<int> ino, vector<int> pre,int& idx,int st,int end){
    if(idx<0){ 
        return NULL;
    }
    if(st>end){
        return NULL;
    }
    int r = pre[idx];
    TreeNode* root  = new TreeNode(r);
    idx--;
    if(st==end){
      return root;
    }
    int xdx = idxinin[r];
    root->right = prein(ino,pre,idx,xdx+1,end);
    root->left = prein(ino,pre,idx,st,xdx-1);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    for(int i=0;i<A.size();i++) 
        idxinin[A[i]] = i;
    int idx = B.size()-1;
    return prein(A,B,idx,0,A.size()-1);
}
