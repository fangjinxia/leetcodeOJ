class Solution {
public:
    class TreeNode{
        public:
            TreeNode* next[2];
            TreeNode(){
                next[0] = NULL;
                next[1] = NULL;
            };
    };
    
    TreeNode* buildTree(vector<int>& nums){
        TreeNode *root = new TreeNode();
        TreeNode *cur;
        for(int j = 0; j < nums.size(); j++){
            int num = nums[j];
            cur = root;
            for(int i = 31; i >= 0; i--){
                int idx = (nums[j] >> i) & 1;
                if(cur->next[idx] == NULL)
                    cur->next[idx] = new TreeNode();
                cur = cur->next[idx];
            }
        }
        
        return root;
    }
    
    int genMax(TreeNode* cur, int num){
        int re = 0;
        for(int i = 31; i >= 0; i--){
            int idx = (num >> i) & 1;
            idx = 1-idx;
            if(cur->next[idx]){
                re <<= 1;
                re |= 1;
                cur = cur->next[idx];
            }
            else{
                re <<= 1;
                re |= 0;
                cur = cur->next[1-idx];
            }
            
        }
        
        return re;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TreeNode *root = buildTree(nums);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, genMax(root, nums[i]));
        }
        
        return ans;
    }
};