int declareIntOfChar(char c)
	{
		int val=0;
		switch(c)
		{
		case 'I':
			val=1;
			break;
		case 'V':
			val=5;
			break;
		case 'X':
			val=10;
			break;
		case 'L' : 
			val=50;
			break;
		case 'C' : 
			val=100;
			break;
		case 'D' : 
			val=500;
			break;
		case 'M' : 
			val=1000;
			break;
		default :
			val=-1;	
			break;
		}
		return val;
}
int Solution::romanToInt(string A) {
    int ans = 0;
    int i;
    for( i = 0; i<A.length()-1; i++){
        if(declareIntOfChar(A[i])>=declareIntOfChar(A[i+1])) ans += declareIntOfChar(A[i]);
        else{
            ans -= declareIntOfChar(A[i]);
         }
    }
    ans += declareIntOfChar(A[i]);
    return ans;
}
