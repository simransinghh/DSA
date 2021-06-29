unordered_map<int,int> idxinin; 
TreeNode* prein(vector<int> ino, vector<int> pre,int& idx,int st,int end){
    // cout<<idx<<st<<end<<" ";
    if(idx>=pre.size()){ 
        idx--;
        return NULL;
    }
    int r = pre[idx];
    TreeNode* root  = new TreeNode(r);
    if(st>end){
        idx--;
        return NULL;
    }
    if(st==end){
      return root;
    }
    int xdx = idxinin[r];
    // cout<<endl<<r<<" "<<xdx<<endl<<"left ";
    root->left = prein(ino,pre,++idx,st,xdx-1);
    // cout<<"right "<<endl;
    root->right = prein(ino,pre,++idx,xdx+1,end);
    // cout<<idx<<endl;
    return root;
}
TreeNode* Solution::buildTree(vector<int> &B, vector<int> &A) {
    for(int i=0;i<A.size();i++) 
        idxinin[A[i]] = i;
    int idx = 0;
    return prein(A,B,idx,0,A.size()-1);
}
