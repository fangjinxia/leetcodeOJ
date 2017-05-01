class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int num = n/2+1;
        for(int i = 1; i < n; i++){
            int k = 1;
            while(i < n && nums[i] == nums[i-1]){
                i++;
                k++;
            }
            if(num <= k)
                return nums[i-1];
        }
        return nums[n-1];
    }
};