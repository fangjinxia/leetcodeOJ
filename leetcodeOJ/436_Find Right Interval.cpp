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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++){
            m[intervals[i].start] = i;
        }
        for(int i = 0; i < intervals.size(); i++){
            map<int,int>::iterator it = m.lower_bound(intervals[i].end);
            if(it == m.end())
                ans.push_back(-1);
            else
                ans.push_back(it->second);
        }
        return ans;
    }
};