class Solution {
public:
    Solution(vector<int> nums) {
        v = nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int ans = -1;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != target)
                continue;
            cnt++;
            if(cnt == 1){
                ans = i;
            }
            else
                if(!(rand()%cnt))
                    ans = i;
            
        }
        return ans;
    }
    
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */