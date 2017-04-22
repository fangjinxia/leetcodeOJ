///<想法就是不断的两两求交集，
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n <= 1){
            return n;
        }
        
        //以xstart排序
        sort(points.begin(), points.end(), [](const pair<int, int>&left, const pair<int, int> &right){
            return left.first < right.first;
        });
        
        //两两相交
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans.push_back(points[i]);
            }
            else if(points[i+1].first > points[i].second){
                ans.push_back(points[i]);
            }
            else{
                points[i+1].second = min(points[i+1].second, points[i].second);
            }
        }
        return ans.size();
    }
};