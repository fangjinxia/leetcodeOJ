//先把所有时间转换为以秒为单位的整数，再计算相邻两个的最小值，注意别忘了第一个和最后一个时间的差值
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time(timePoints.size(), 0);
        for(int i = 0; i < timePoints.size(); i++){
            int idx = timePoints[i].find(':');//找到分割小时和分钟的分隔符
            string hour = timePoints[i].substr(0, idx);
            string minute = timePoints[i].substr(idx+1);
            time[i] = atoi(hour.c_str()) * 60 + atoi(minute.c_str());
        }
        
        sort(time.begin(), time.end());
        int ans = 24*60;
        for(int i = 1; i < time.size(); i++){
            ans = min(ans, time[i]-time[i-1]);
        }
        ans = min(ans, 24*60-time[time.size()-1]+time[0]);
        return ans;
    }
};