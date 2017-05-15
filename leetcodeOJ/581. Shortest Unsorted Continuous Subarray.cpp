class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(), v.end());
        
        int re = 0;
        int i = 0;
        for(; i < v.size(); i++){
            if(nums[i] != v[i])
                break;
            re++;
        }
        for(int j = v.size()-1; j > i; j--){
            if(nums[j] != v[j])
                break;
            re++;
        }
        return nums.size()-re;
    }
};