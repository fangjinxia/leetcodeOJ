class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size()-1;
        vector<int> ans(2);
        while(lo < hi){
            int sum = numbers[lo] + numbers[hi];
            if(sum == target){
                ans[0] = lo+1;
                ans[1] = hi+1;
                return ans;
            }
            else if(sum < target){
                lo++;
            }
            else{
                hi--;
            }
        }
    
    }
};