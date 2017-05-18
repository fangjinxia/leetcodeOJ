class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        if(findNums.size() == 0)
            return ans;
            
        for(int i = 0; i < findNums.size(); i++){
            vector<int>::iterator idx = find(nums.begin(), nums.end(), findNums[i]);
            for(; idx != nums.end(); idx++){
                if(*idx > findNums[i]){
                    ans.push_back(*idx);
                    break;
                }
            }
            if(idx == nums.end())
                ans.push_back(-1);
            
        }
        
        return ans;
    }
};