vector<string> gcode(int n){
        if(n == 0){
                return {"0"};
        }
        if(n == 1){
                return {"0","1"};
        }
        int x = pow(2,n);
        vector<string> temp = gcode(n-1);
        vector<string> ans(x);
        int i;
        for(i=0;i<temp.size();i++){
                ans[i] = "0" + temp[i];
        }
        int j;
        for(j=temp.size()-1;j>=0;j--){
                ans[i] = "1" + temp[j];
                i++;
        }
        return ans;
}
int binaryToDecimal(string n)
{
    int i =n.size()-1;
    int dec_value = 0;
    int base = 1;
    while (i>=0) {
        int last_digit = n[i] - '0';
        i--;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}
vector<int> Solution::grayCode(int A) {
        vector<int>  ans;
    vector<string> a = gcode(A);
    for(int i = 0 ; i<a.size();i++){
            int n = binaryToDecimal(a[i]);
            ans.push_back(n);
    }
    return ans;
}
