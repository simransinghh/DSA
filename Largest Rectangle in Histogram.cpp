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
};
