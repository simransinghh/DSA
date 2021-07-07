void helper(string A,string aux,set<string>s,vector<string>&v)
{
    if(A=="")
    {
        if(!aux.empty())
        {
            aux.erase(aux.begin()+aux.length()-1);
        }
        v.push_back(aux);
        return;
    }
    for(int i=1;i<=A.length();i++)
    {
        string first=A.substr(0,i);
        string second=A.substr(i);
        if(s.find(first)!=s.end())
        {
            string prev=aux;
            aux=aux+first+" ";
            helper(second,aux,s,v);
            aux=prev;
        }
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) 
{
    set<string>s;
    for(auto it:B)
    {
        s.insert(it);
    }
    B.clear();
    vector<string>v;
    helper(A,"",s,v);
    s.clear();
    return v;
}
