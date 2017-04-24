class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1])
                return nums[i];
        }
        return nums[0];
               
    }
};


///<¶þ·Ö·¨
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size()-1;
        while(lo < hi){
            if(nums[lo] < nums[hi])
                return nums[lo];
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[hi])
                lo = mid+1;
            else if(nums[mid] < nums[hi])
                hi = mid;
            else  ///<we couldn't sure the position of minimum in mid's left or right, so just let upper bound reduce one.
                hi--;
        }
        return nums[lo];
    }
};