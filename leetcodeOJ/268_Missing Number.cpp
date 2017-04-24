class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};

//another smart method
int missingNumber(vector<int>& nums) {
    long n = nums.size();
    return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
}