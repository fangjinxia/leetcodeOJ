//数学问题
//m*(n-1)+sum = x*n
//x = m+minNum
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int minNum = nums[0];
        
        int x = sum - (n-1)*minNum;
        return x-minNum;
    }
};