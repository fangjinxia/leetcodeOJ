class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1 = 1;//��ǰ�����
        int p2 = 1;//�Ӻ���ǰ��
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            p1 *= nums[i];
            p2 *= nums[n-1-i];
            //cout << p2 << endl;
            ans = max(ans, max(p1, p2));
            p1 = nums[i]==0 ? 1 : p1;
            p2 = nums[n-1-i]==0 ? 1 : p2;
        }
        return ans;
        
    }
};