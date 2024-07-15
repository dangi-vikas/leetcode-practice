class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    double area = 0;
                    vector<int> a, b, c;
                    
                    a = points[i], b = points[j], c = points[k];
                    area = abs(findArea(a, b) + findArea(b, c) + findArea(c, a));
                    
                    if(area > maxArea) maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
    
    double findArea(vector<int> a, vector<int>& b) {
        int l = b[0] - a[0];
        double h = (a[1] + b[1] + 200) / 2.0;
        return l * h;
    }
};