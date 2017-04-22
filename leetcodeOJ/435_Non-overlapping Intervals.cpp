/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n < 2){
            return 0;
        }
        
        ///<以起始节点排序
        sort(intervals.begin(), intervals.end(), [](const Interval &left, const Interval &right){
            return left.start < right.start;
        });
        
        vector<Interval> ans;
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i].end <= intervals[i+1].start){
                ans.push_back(intervals[i]);
            }
            else{
                intervals[i+1].end = min(intervals[i].end, intervals[i+1].end);
            }
        }
        
        return n-ans.size();
    }
};