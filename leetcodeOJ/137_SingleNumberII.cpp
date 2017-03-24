class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //�Լ�û�����������±��˵�˼·
        //����ÿ��num��ÿ��bitλ�ϵ�Ϊ1�ĸ����ͣ�
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int n = 0;
            for(int j = 0; j < nums.size(); j++){
                if(((nums[j] >> i) & 1) == 1)
                    n++;
            }
            n %= 3;
            
            if(n)
                ans += (n << i);
        }
        
        return ans;
    }
};