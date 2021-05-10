vector<vector<int> > Solution::generateMatrix(int A) {
    
        vector<vector<int>> ans(A,vector<int>(A,0));
    if(A == 0){
        return ans;
    }
    char dir = 'r';
    int no = 1;
    int x=0 , y=0;
    while(no <= pow(A,2)){
        if(dir=='r'){
            while(x<A && y<A && ans[x][y]==0 && x>=0 && y>=0){
                ans[x][y] = no;
                no++;
                y++;
            }
            y--;
            x++;
            dir = 'd';
            if(ans[A/2][A/2] == pow(A,2)){
                return ans;
            }
        }
        if(dir=='d'){
            while(x<A && y<A && ans[x][y]==0 && x>=0 && y>=0){
                ans[x][y] = no;
                no++;
                x++;
            }
            x--;
            y--;
            dir = 'l';
            if(ans[A/2][A/2] == pow(A,2)){
                return ans;
            }
        }
        if(dir=='l'){
            while(x<A && y<A && ans[x][y]==0 && x>=0 && y>=0){
                ans[x][y] = no;
                no++;
                y--;
            }
            y++;
            x--;
            dir = 'u';
            if(ans[A/2][A/2] == pow(A,2)){
                return ans;
            }
        }
        if(dir=='u'){
            while(x<A && y<A && ans[x][y]==0 && x>=0 && y>=0){
                ans[x][y] = no;
                no++;
                x--;
            }
            y++;
            x++;
            dir = 'r';
            if(ans[A/2][A/2] == pow(A,2)){
                return ans;
            }
        }
    }
    return ans;
    
}
