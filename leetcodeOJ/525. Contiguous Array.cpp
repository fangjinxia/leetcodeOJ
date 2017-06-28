//binary array Ö»°üº¬0ºÍ1
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res = 0;
        
        map<int, int> m;
        map<int, int>::iterator it;
        m[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += (nums[i] == 0) ? -1 : 1;
            it = m.find(sum);
            if(it != m.end())
                res = max(res, i-it->second);
            else
                m[sum] = i;
        }
        
        return res;
    }
};