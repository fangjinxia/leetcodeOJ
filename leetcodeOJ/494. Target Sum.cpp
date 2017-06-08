class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int num0 = 1;
        vector<int> num(0);
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(nums[i] == 0)
                num0 *= 2;
            else
                num.push_back(nums[i]);
        }
        
        if((sum-S) % 2 == 1)
            return 0;
        int s = (sum-S)>>1;
        //sΪ��Ҫ��ȥ�����ĺ�
        sort(num.begin(), num.end());
        vector<vector<int>> ans(0);//��ź�Ϊs��Ԫ�����
        vector<int> re(0);//��ŵ�ǰ���
        
        
        genAns(num, ans, re, s, 0);
        
        
        return ans.size()*num0;
    }
    
    //nums����ɾ������0
    void genAns(vector<int>& nums, vector<vector<int>>& ans, vector<int>& re, int target, int i){
        if(i > nums.size())
            return ;
        if(target == 0){
            ans.push_back(re);
            return ;
        }
        if(target < nums[i]){
            return ;
        }
    
        if(target >= nums[i]){
            re.push_back(nums[i]);
            genAns(nums, ans, re, target-nums[i], i+1);
            re.pop_back();
            genAns(nums, ans, re, target, i+1);
        }
        
    }
};