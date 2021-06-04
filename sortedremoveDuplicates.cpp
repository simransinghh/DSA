int Solution::removeDuplicates(vector<int> &A) {
     
     for(int i=0;i<A.size()-1;i++){
         if(A[i]==A[i+1]) {
             A.erase(A.begin()+i+1);
             i--;
         }
     }
     return A.size();
}
