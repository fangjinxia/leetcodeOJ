//动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int ans = nums[0];
        int local = nums[0];
        for(int i = 1; i < n; i++){
            local = max(nums[i], local+nums[i]);//local每次都包含当前元素，
            ans = max(ans, local);
        }
        return ans;
    }
};

//使用分治方法
// mx (largest sum of this subarray), 
// lmx(largest sum starting from the left most element), 
// rmx(largest sum ending with the right most element), 
// sum(the sum of the total subarray). 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int mx, lmx, rmx, sum;
        maxSubArrHelper(nums, 0, n-1, mx, lmx, rmx, sum);
        return mx;
    }
    
private:
    void maxSubArrHelper(vector<int>& nums, int start, int end, int& mx, int& lmx, int& rmx, int& sum){
        if(start == end)
            mx = lmx = rmx = sum = nums[start];
        else{
            int mid = start + (end - start)/2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArrHelper(nums, start, mid, mx1, lmx1, rmx1, sum1);
            maxSubArrHelper(nums, mid+1, end, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1+lmx2);
            lmx = max(sum1+lmx2, lmx1);
            rmx = max(rmx1+sum2, rmx2);
            sum = sum1 + sum2;
        }
    }
};