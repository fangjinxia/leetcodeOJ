class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums)
            m[num]++;
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > m.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return ans;
    }
};