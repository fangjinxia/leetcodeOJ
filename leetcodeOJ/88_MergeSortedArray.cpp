/*
因为知道两个数组的大小，就知道合并之后的数组的大小，因此从后往前比较即可，
如果nums2已经全部插入到nums1中，即j<0，此时nums1就已经全部排好序了。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
        while(j >= 0){
            nums1[k] = (i >= 0 && nums1[i] > nums2[j])?nums1[i--] : nums2[j--];
            k--;
        }
    }
};