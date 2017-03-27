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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if(!intervals.size()){
            ans.push_back(newInterval);
            return ans;
        }
        bool flag = true;
        for(int i = 0; i < intervals.size(); i++){
            if(flag == false || newInterval.start > intervals[i].end)
                ans.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                flag = false;
            }
            else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        if(flag)
            ans.push_back(newInterval);
        
        return ans;
        
    }
};