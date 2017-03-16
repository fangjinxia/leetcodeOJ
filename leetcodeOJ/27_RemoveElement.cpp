class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                vector<int>::iterator iter = nums.begin() + i;
                nums.erase(iter);
                i--;//因为每次删除一个元素之后，nums.size()都减一，所以i需要往回退一
            }
        }
        return nums.size();
    }
    
};