string ans;
void Maxstr(string A,int B,int index)
{
if(B==0) return;

    for(int i=index;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            swap(A[i],A[j]);
            if(A>=ans) ans=A;
            Maxstr(A,B-1,index+1);
            swap(A[i],A[j]);
        }
    }
}


string Solution::solve(string A, int B) {
    ans=A;
    Maxstr(A,B,0);
    return ans;
    
}
