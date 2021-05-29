vector<int> numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
string Solution::intToRoman(int A) {
    string ans;
    int tens = 0;
    while(A>0){
       int z = pow(10,tens);
       int remail = A%10;
       A = A/10;
       if(remail == 0){
           tens++;
           continue;
       }
       remail = remail * z;
       int i;
       for(i = 0; i<numbers.size(); i++){
           if(remail == numbers[i]){
            ans = roman[i] + ans;
            break;
           }
           else if(remail<numbers[i]){
               continue;
           }else{
               int x = remail-numbers[i];
                ans = roman[i] + intToRoman(x) + ans;
                break;
           }
       }
       tens++;
    }
    return ans;
}
