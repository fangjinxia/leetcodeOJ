class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++){
            map<int, int>::iterator it = numMap.find(nums[i]);
            if(it == numMap.end())
                numMap[nums[i]] = i;
            else{
                if(i - it->second <= k)
                    return true;
                else
                    it->second = i;
            }
        }
        return false;
    }
};