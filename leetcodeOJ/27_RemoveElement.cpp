class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                vector<int>::iterator iter = nums.begin() + i;
                nums.erase(iter);
                i--;//��Ϊÿ��ɾ��һ��Ԫ��֮��nums.size()����һ������i��Ҫ������һ
            }
        }
        return nums.size();
    }
    
};