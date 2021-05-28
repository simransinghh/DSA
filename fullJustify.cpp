vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> ans;
    int temp = B;
    for(int i=0;i<A.size();i++){
        string a;
        if(A[i].length()<B){
            a = A[i];
            temp = temp - A[i].length()-1;
            i++;
        }
        else if(A[i].length() == B){
            a = A[i];
            temp = 0;
        }
        else{
            return ans;
        }
        int start = i;
        while(temp>0 && i<A.size()){
            if(A[i].length()<temp){
                temp = temp - A[i].length()-1;
                i++;
            }
            else if(A[i].length() == temp){
                temp = 0;
                for(int j = start;j<=i;j++){
                    a = a + " " + A[j];
                }
            }
            else{
                int divide = i - 1 - start;
                int remain = temp%divide;
                temp = temp/divide;
                int j = start;
                while(remain>0 || j>i){
                    for(int k=0;k<=temp;k++){
                        a = a = " ";
                    }
                    if(remain>0){
                        a = a + " ";
                    }
                    a = a + A[j];
                }
                temp = 0;
            }
            if(i == A.size()){
               for(int j = start;j<i;j++){
                    a = a + " " + A[j];
                }
            }

        }
        ans.push_back(a);
        temp = B;
    }
    return ans;
}
