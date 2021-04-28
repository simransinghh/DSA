int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    queue<pair<int,int>> q;
    q.push(make_pair(C,D));
    int step[A+1][B+1];
    int e = INT_MAX;
    for(int i=0; i<=A; i++){
		for(int j=0; j<=B; j++){
  			step[i][j] = e;
        }
    }
    step[C][D]=0;
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();
        if(x.first+1<=A && x.second+2<=B){
            q.push(make_pair(x.first+1,x.second+2));
            if(x.first+1==E && x.second+2==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first+1][x.second+2] = min(step[x.first+1][x.second+2],step[x.first][x.second] + 1);
        }
        if(x.first-1>0 && x.second+2<=B){
            q.push(make_pair(x.first-1,x.second+2));
            if(x.first-1==E && x.second+2==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first-1][x.second+2] = min(step[x.first-1][x.second+2],step[x.first][x.second] + 1);
        }
        if(x.first+2<=A && x.second+1<=B){
            q.push(make_pair(x.first+2,x.second+1));
            if(x.first+2==E && x.second+1==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first+2][x.second+1] = min(step[x.first+2][x.second+1],step[x.first][x.second] + 1);
        }
        if(x.first-2>0 && x.second+1<=B){
            q.push(make_pair(x.first-2,x.second+1));
            if(x.first-2==E && x.second+1==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first-2][x.second+1] = min(step[x.first-2][x.second+1],step[x.first][x.second] + 1);
        }
        if(x.first-2>0 && x.second-1>0){
            q.push(make_pair(x.first-2,x.second-1));
            if(x.first-2==E && x.second-1==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first-2][x.second-1] = min(step[x.first-2][x.second-1],step[x.first][x.second] + 1);
        }
        if(x.first+2<=A && x.second-1>0){
            q.push(make_pair(x.first+2,x.second-1));
            if(x.first+2==E && x.second-1==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first+2][x.second-1] = min(step[x.first+2][x.second-1],step[x.first][x.second] + 1);
        }
        if(x.first-1>0 && x.second-2>0){
            q.push(make_pair(x.first-1,x.second-2));
            if(x.first-1==E && x.second-2==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first-1][x.second-2] = min(step[x.first-1][x.second-2],step[x.first][x.second] + 1);
        }
        if(x.first+1<=A && x.second-2>0){
            q.push(make_pair(x.first+1,x.second-2));
            if(x.first+1==E && x.second-2==F){
                return step[x.first][x.second] + 1;
            }
            step[x.first+1][x.second-2] = min(step[x.first+1][x.second-2],step[x.first][x.second] + 1);
        }

    }
    return -1;
}
