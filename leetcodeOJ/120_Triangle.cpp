//��̬�滮
//˼·���Կռ临�Ӷ���Ҫ������һ��n��С�����飬��ʼ��Ϊ��n-1�е�Ԫ�أ�
//������ö�̬�滮���⣬�������ϴ�����i�е�j��Ԫ�ص�ֵΪ��min����i+1�е�j��Ԫ�أ���i+1�е�j+1��Ԫ�أ�+  ��i�е�j��Ԫ�أ�
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans[n];
        for(int i = 0; i < n; i++){
            ans[i] = triangle[n-1][i];//��ʼ��Ϊ���һ��
        }
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1-i; j++){
                ans[j] = triangle[n-2-i][j] + min(ans[j], ans[j+1]);
            }
        }
        return ans[0];
    }
};