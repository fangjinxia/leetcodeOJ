/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 //思路：计算几何问题，给定一些点集，计算在一条直线上的最多点，
 //没想到啥好办法，n个点，一共n*(n-1)条直线，用循环就行，重点在于如何判断一点在直线上
 //注意边界情况和一些细节，比如n=1,n=2
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max = 0;
        int n = points.size();
        if(n == 0 || n == 1 || isAllSame(points))
            return n;
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    continue;
                int temp = 2;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)
                        continue;
                    //小心溢出
                    if(((long)(points[k].y - points[i].y) * (long)(points[j].x - points[i].x)) == ((long)(points[k].x - points[i].x) * (long)(points[j].y - points[i].y))){//判断k点在直线ij上
                        temp++;
                    }
                }
                max = (temp > max) ? temp : max;
                
            }
        }
        return max;
    }
    
private:
    bool isAllSame(vector<Point>& points){
        //所有的点都一样
        for(int i = 1; i < points.size(); i++){
            if(points[i].x != points[0].x || points[i].y != points[0].y)
                return false;
        }
        return true;
    }
};
