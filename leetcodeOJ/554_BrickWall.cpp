//�����ڿ������ۼӣ����״�0��ʼ�������ҵ��м�ֵ�������Ĵ�����ǽ���������
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int m = wall.size();//mΪǽ��
        if(m == 0)  
            return 0;
        int sum = accumulate(wall[0].begin(), wall[0].end(), 0);
        map<int, int> v;
        int ans = 0;
        for(int i = 0; i < m; i++){
            int height = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                height += wall[i][j];
                v[height]++;
                ans = max(ans, v[height]);
            }
        }
        return m-ans;
    }
};