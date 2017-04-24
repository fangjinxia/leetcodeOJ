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

///<another method----binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            if(nums[hi] > nums[lo])
                return nums[lo];
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[hi])
                lo = mid+1;
            else
                hi = mid;
          //  cout << lo << ' ' << hi << endl;
        }
        return nums[lo];
    }
};