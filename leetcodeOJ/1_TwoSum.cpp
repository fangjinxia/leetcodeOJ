class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;//返回的结果

        int numToFind = 0;
        for(int i = 0; i < nums.size(); i++){
            numToFind = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(i == j){
                    continue;
                }
                else{
                    if(numToFind == nums[j]){
                        if(i < j){
                            res.push_back(i);
                            res.push_back(j);
                            return res;
                        }
                        else{
                            res.push_back(j);
                            res.push_back(i);
                            return res;
                        }
                    }
                }
            }
        }
    }
};
