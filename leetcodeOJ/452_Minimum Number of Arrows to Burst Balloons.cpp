///<�뷨���ǲ��ϵ������󽻼���
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n <= 1){
            return n;
        }
        
        //��xstart����
        sort(points.begin(), points.end(), [](const pair<int, int>&left, const pair<int, int> &right){
            return left.first < right.first;
        });
        
        //�����ཻ
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