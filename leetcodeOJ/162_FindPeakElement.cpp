//要求时间复杂度logn
//考虑二分法，找出一个peak element就成
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size()-1;
        
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < nums[mid+1]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        
        return lo;
    }
};