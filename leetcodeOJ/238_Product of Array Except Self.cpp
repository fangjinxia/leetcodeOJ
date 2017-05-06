class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int product = 1;
        vector<int> idxOfZero(0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                idxOfZero.push_back(i);
            else
                product *= nums[i];
        }
        
        if(idxOfZero.size() >= 2)//如果0的个数大于等于2，则输出全0
            return ans;
        else if(idxOfZero.size() == 1){
            ans[idxOfZero[0]] = product;
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
};