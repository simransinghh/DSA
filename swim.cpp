#include<bits/stdc++.h>
using namespace std;

class Foo
    {
        public:
        int x;
        int y;
        int depth;
        bool visited;
        
        Foo(int x,int y,int depth){
            this->x=x;
            this->y=y;
            this->depth=depth;
            this->visited = false;
        }

    };
    class Compare
    {
    public:
        bool operator() (Foo a, Foo b)
        {
            return a.depth > b.depth;
        }
    };
int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int i=0,j=0, ans = 0;
        Foo l(i,j,grid[i][j]);
        priority_queue <Foo, vector<Foo>, Compare> g;
        g.push(l);
        Foo f = l;
        while(i!=n-1 && j!=n-1){
            Foo minn(0,0,INT_MAX);
            if(grid[i+1][j] > f.depth && i+1<n && j<n && i+1>=0 && j>=0){
              Foo down(i+1,j,grid[i+1][j]);
              minn = down;
              g.push(down);
            }
            if(grid[i-1][j] > f.depth && i-1<n && j<n && i-1>=0 && j>=0){
              Foo up(i-1,j,grid[i-1][j]);
              if(minn.depth>grid[i-1][j]){
                  minn = up;
              }
              g.push(up);
            }
            if(grid[i][j+1] > f.depth && i<n && j+1<n && i>=0 && j+1>=0){            
              Foo right(i,j+1,grid[i][j+1]);
              if(minn.depth>grid[i][j+1]){
                  minn = right;
              } 
              g.push(right);
            }
            if(grid[i][j-1] > f.depth && i<n && j-1<n && i>=0 && j-1>=0){                
              Foo left(i,j-1,grid[i][j-1]);
              if(minn.depth>grid[i][j-1]){
                  minn = left;
              }
              g.push(left);
            }
            if(g.top().depth <minn.depth){
                f = g.top();
                i = f.x;
                j = f.y;
                ans = f.depth;
                g.pop();
            }else{
                f = minn;
                i = f.x;
                j = f.y;
            }
        }
        return ans;
    }
int main()
{
     vector< vector<int> > grid={{0,2},{1,3}};
    cout<<swimInWater(grid);
    return 0;
}
