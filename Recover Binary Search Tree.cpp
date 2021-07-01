bool one = false;
bool two = false;
void recovering(TreeNode* root,int &prev1,int& next1,int &prev2,int &next2){
    if(one && two) return;
    if(root==NULL) return;
    // cout<<endl<<root->val<<"-";
    recovering(root->left,prev1,next1,prev2,next2);
    if(!one){
        if(root->val < prev1){
            one = true;
            next1 = root->val;
            // cout<<"n1"<<root->val<<endl;
        }
        else{ 
            // cout<<"p1"<<root->val<<endl;
            prev1 = root->val;
        }
    }
    else if(!two){
       if(root->val < prev2){
           next2 = root->val;
        //   cout<<"n2"<<root->val<<endl;
           two = true;
        }
        else{ 
            // cout<<"p2"<<root->val<<endl;
            prev2 = root->val; 
        }
    }
    else if(one && two) return;
    prev2 = root->val;
    // cout<<"r"<<prev2<<"   ";
    recovering(root->right,prev1,next1,prev2,next2);
    return;
}
vector<int> Solution::recoverTree(TreeNode* A) {
    int prev1 = INT_MIN;
    int prev2 = INT_MIN;
    int next1,next2;
    one = false;
    two = false;
    recovering(A,prev1,next1,prev2,next2);
    vector<int> ans;
    // cout<<prev1<<next1<<prev2<<" "<<next2<<" "<<one<<two<<endl;
    if(!two){
       ans.push_back(next1);
       ans.push_back(prev1);
       return ans;
    }
    ans.push_back(next2);
    ans.push_back(prev1);
    return ans;
}
