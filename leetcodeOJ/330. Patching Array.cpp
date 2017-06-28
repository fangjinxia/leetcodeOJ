//Ì°ÐÄËã·¨
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0, i = 0;
        long long maxNum = 0;
        
        while(maxNum < n){
            if(i < nums.size() && maxNum+1 >= nums[i])
                maxNum += nums[i++];
            else{
                maxNum += maxNum+1;
                ++res;
                
            }
        }
        
        return res;
    }
};