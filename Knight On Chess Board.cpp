struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
bool isInside(int x, int y, int A , int B)
{
    if (x >= 1 && x <= A && y >= 1 && y <= B)
        return true;
    return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    queue<cell> q;
    q.push(cell(C,D,0));
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    cell t;
    int x, y;
    bool visit[A + 1][B + 1];
  
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            visit[i][j] = false;
  
    visit[C][D] = true;
  
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t.x == E && t.y == F)
            return t.dis;
  
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (isInside(x, y, A , B) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
    return -1;
}
   

