class Solution {
public:
    double getMidth(vector<int>& num1, int l, vector<int>& num2, int r, int k){
        if(l >= num1.size())
            return num2[r+k-1];
        if(r >= num2.size())
            return num1[l+k-1];
            
        if(k == 1)
            return min(num1[l], num2[r]);
            
        int num1Mid = INT_MAX;
        int num2Mid = INT_MAX;
        if(l + k/2 - 1 < num1.size())
            num1Mid = num1[l + k/2 - 1];
        if(r + k/2 - 1 < num2.size())
            num2Mid = num2[r + k/2 - 1];
            
        if(num1Mid < num2Mid)
            return getMidth(num1, l+k/2, num2, r, k-k/2);
        else
            return getMidth(num1, l, num2, r+k/2, k-k/2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ///<使用分治
        int m = nums1.size();
        int n = nums2.size();
        int l = (m+n+1)/2;
        int r = (m+n+2)/2;
        
        double ans = (getMidth(nums1, 0, nums2, 0, l) + getMidth(nums1, 0, nums2, 0, r)) / 2.0;
        return ans;
    }
};