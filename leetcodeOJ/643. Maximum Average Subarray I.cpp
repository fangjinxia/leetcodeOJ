class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();        
        int sum = accumulate(nums.begin(), nums.begin()+k, 0);
        //cout << sum << endl;
        if(n == k)
            return (double)sum/k;
        
        int tmp = sum;
        for(int i = k; i < n; ++i){
            tmp += (nums[i] - nums[i-k]);
            sum = max(sum, tmp);
        }
        
        return (double)sum/k;
    }
};