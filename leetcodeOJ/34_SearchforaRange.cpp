class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ///<˼·����Ϊʱ�临�Ӷ�Ϊlogn��������������ô���Բ��ö��ַ�
        int left = 0;
        int right = nums.size()-1;
        
        int mid = 0;
        vector<int> ans(2, -1);
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] == target){
                int k = mid-1;
                while(nums[k] == target && k >= 0){ ///<ע��߽�
                    k--;
                }
                ans[0] = k+1;
                k = mid+1;
                while(nums[k] == target && k <= (nums.size()-1)){///<ע��߽�
                    k++;
                }
                ans[1] = k-1;
                
                return ans;
            }
        }
        
        return ans;
    }
};