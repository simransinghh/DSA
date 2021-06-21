typedef long long ll;
string Solution::fractionToDecimal(int A, int B) {
    if(A==0) return "0";
    if(B==0) return "invalid";
    long long a=(long long)A;
    long long b=(long long)B;
    int sign=(a<0)^(b<0)?-1:1;
    a=abs(a);
    b=abs(b);
    long long initial=a/b;
    string res;
    if(sign==-1)
    {
    res+="-";
    }
    res+=to_string(initial);
    if(a%b==0)
    {
        return res;
    }
    res+=".";
    long long rem=a%b;
    unordered_map<ll,ll> m;
    long long index;
    bool repeat =false;
    while(rem>0&&repeat==false)
    {
        if(m.find(rem)!=m.end())
        {
            index=m[rem];
            repeat=true;
            break;
        }
        else
        {
            m[rem]=res.size();
        }
        rem=rem*10;
        long long temp=rem/b;
        res+=to_string(temp);
        rem=rem%b;
    }
        if(repeat==true)
        {
            res+=")";
            res.insert(index,"(");
        }
        return res;
}
