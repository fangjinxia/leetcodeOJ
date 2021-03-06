class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                do{
                    i++;
                }while(nums1[i] == nums1[i-1]);
                do{
                    j++;
                }while(nums2[j] == nums2[j-1]);
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};