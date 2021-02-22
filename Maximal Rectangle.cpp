class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ar , k , area = INT_MIN;
        for(int i=0;i<heights.size();i++){
            if(s.empty() || heights[s.top()]<heights[i]){
                s.push(i);
            }
            else if(heights[s.top()]==heights[i]){
                s.pop();
                s.push(i);
            }
            else{
                while(!s.empty() && heights[i]<heights[s.top()] ){
                    int h = s.top();
                    s.pop();
                    if(s.empty()){
                        ar = heights[h]*(i);
                    }
                    else{
                        ar = heights[h]*(i-s.top()-1);
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
                        ar = heights[h]*(k+1);
                    }
                    else{
                        ar = heights[h]*(k-s.top());
                    }
                    area = max(ar,area);
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        int ans = INT_MIN;
    vector<vector<int>> intmatrix( matrix.size() , vector<int> (matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++){
                intmatrix[i][j] = matrix[i][j]-'0';
            }
        }
        ans = max(ans,largestRectangleArea(intmatrix[0]));
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++){
                if(intmatrix[i][j]==1){
                    intmatrix[i][j] += intmatrix[i-1][j];
                }
            }
            ans = max(ans,largestRectangleArea(intmatrix[i]));
        }
        return ans;
    }
};
