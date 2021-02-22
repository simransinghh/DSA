#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<char>& heights) {
    stack<int> s;
    int ar , k , area = INT_MIN;
    for(int i=0;i<heights.size();i++){
        if(s.empty() || ((heights[s.top()]-'0')<(heights[i]-'0'))){
                s.push(i);
            }
            else if(heights[s.top()]==heights[i]){
                s.pop();
                s.push(i);
            }
            else{
                while(!s.empty() && ((heights[i]-'0')<(heights[s.top()]-'0')) ){
                    int h = s.top();
                    s.pop();
                    if(s.empty()){
                        ar = (heights[h]-'0')*(i);
                    }
                    else{
                        ar = (heights[h]-'0')*(i-s.top()-1);
                    }
                    area = max(ar,area);
                }
                s.push(i);
            }

        }
        if(!s.empty()){            
            k = s.top();
        }
        while(!s.empty()){
            int h = s.top();
            s.pop();
                    if(s.empty()){
                        ar = (heights[h]-'0')*(k+1);
                    }
                    else{
                        ar = (heights[h]-'0')*(k-s.top());
                    }
                    area = max(ar,area);
        }
        return area;
    }
int main()
{
    vector<vector<char>> matrix = { {'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'} };
    int ans = INT_MIN;
    ans = max(ans,largestRectangleArea(matrix[0]));
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = (char)((matrix[i][j]-'0') + (matrix[i-1][j]-'0'));
        }        
        ans = max(ans,largestRectangleArea(matrix[i]));
    }
    cout<<ans;
    return 0;
}
