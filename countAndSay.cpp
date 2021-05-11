string Solution::countAndSay(int A) {
    string ans;
    if(A == 1){
        ans = "1";
        return ans;
    }
    if(A == 2){
        ans = "11";
        return ans;
    }
    string minusone = countAndSay(A-1);
    int same = 1;
    for(int i = 0; i < minusone.length();i++){
        if(i == minusone.length()-1){
            string times = to_string(same);
            ans = ans + times + minusone[i];
            same = 1;
            break;
        }
        if(minusone[i] == minusone[i+1]){
            same++;
            continue;
        }
        else{
            string times = to_string(same);
            ans = ans + times + minusone[i];
            same = 1;
        }
    }
    return ans;
}
