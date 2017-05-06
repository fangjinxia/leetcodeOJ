class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return false;
        int sum = 0;
        vector<int> v(0);
        v.push_back(0);
        v.push_back(nums[0]);
        sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            v.push_back(sum);
            for(int j = i-1; j >= 0; j--){
                if((k != 0 ) && ((v[i+1] - v[j]) % k == 0)){
                    return true;
                }
                else if(k == 0 && (v[i+1]-v[j] == 0)){
                    return true;
                }
            }
        }
        return false;
    }
};