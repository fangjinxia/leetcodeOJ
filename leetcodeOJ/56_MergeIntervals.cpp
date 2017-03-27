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
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> ans;
        if(intervals.size() == 0)
            return ans;
            
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start > ans.back().end)
                ans.push_back(intervals[i]);
            else
                ans.back().end = (intervals[i].end > ans.back().end) ? intervals[i].end : ans.back().end;
            
        }
        return ans;
    }
};