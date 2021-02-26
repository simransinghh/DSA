class Solution {
public:
    class line{
        public:
      float slope;
      int xx;
      int yy;
      line(float slope, int xx ,int yy){
          this->slope = slope;
          this->xx = xx;
          this->yy = yy;
      }
      bool operator == (line a,line b) {
          if(a.slope == b.slope){
              return true;
          }
          retrun false;
}
    };
    class myhash{
        public:
         size_t operator()(const line& p) const
        { 
            return hash<int>()(p.slope)+p.xx+p.yy; 
        } 
    }; 
    int maxPoints(vector<vector<int>>& points){
        int maxa = INT_MIN;
        unordered_map<Solution::line,int,Solution::myhash> slopeno;
        unordered_map<float,int> vertislopeno;
        for(int i=0; i<points.size()-1;i++){
            for(int j=i+1; j<points.size(); j++ ){
                float slopee;
                float no = (points [j][0] - points[i][0]) + 0.0;
                float no2 = (points[j][1] - points[i][1]) + 0.0;
                if((points[j][1] - points[i][1]) != 0){
                    slopee = no / no2;
                    Solution::line q(slopee,points [j][0],points[j][1]) ;
                    slopeno[q]++;  
                    maxa = max(slopeno[q],maxa);
                }
                else{
                    slopee = points[j][1];
                    vertislopeno[slopee]++;  
                    maxa = max(vertislopeno[slopee],maxa);
                
                }
            }
        }
        return maxa;
    }
};
