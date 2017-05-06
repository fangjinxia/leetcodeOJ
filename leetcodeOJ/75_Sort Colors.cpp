class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

//��������
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //���ü�������
        int cnt[3] = {0};
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        int idx = 0;
        for(int i = 0; i < cnt[0]; i++){
            nums[idx++] = 0;
        }
        for(int i = 0; i < cnt[1]; i++){
            nums[idx++] = 1;
        }
        for(int i = 0; i < cnt[2]; i++){
            nums[idx++] = 2;
        }
        return ;
    }
};