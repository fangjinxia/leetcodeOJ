//�Ȱ�����ʱ��ת��Ϊ����Ϊ��λ���������ټ���������������Сֵ��ע������˵�һ�������һ��ʱ��Ĳ�ֵ
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time(timePoints.size(), 0);
        for(int i = 0; i < timePoints.size(); i++){
            int idx = timePoints[i].find(':');//�ҵ��ָ�Сʱ�ͷ��ӵķָ���
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