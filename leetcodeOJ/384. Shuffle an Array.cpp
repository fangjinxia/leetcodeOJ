class Solution {
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        
        v.resize(nums.size());
        arr.resize(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            v[i] = nums[i];
            arr[i] = nums[i];
        }
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i = 0; i < v.size(); ++i)
            v[i] = arr[i];
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = v.size()-1; i > 0; --i){
            int tmp = rand() % (i+1);
            swap(v[i], v[tmp]);
        }
        
        return v;
    }

private:
    vector<int> v, arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */