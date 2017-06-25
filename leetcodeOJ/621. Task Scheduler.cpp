class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for(auto c : tasks){
            ++v[c-'A'];
        }
        int cnt = *max_element(v.begin(), v.end());
        int ans = (cnt-1) * (n+1);
        ans += count(v.begin(), v.end(), cnt);
        
        return max(ans, (int)tasks.size());
    }
};