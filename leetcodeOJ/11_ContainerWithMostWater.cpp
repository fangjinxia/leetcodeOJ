// O(n)�ĸ��Ӷȡ���������ָ��i,j��
// �ֱ�ָ�򳤶��������β��
// ���ai С��aj�����ƶ�i���i++����
// ��֮���ƶ�j��ǰ��j--����
// �����ǰ��area����������¼��area���滻֮��
// ����뷨�Ļ����ǣ����i�ĳ���С��j, ��������ƶ�j���̰���i��
// �������ҵ��ȵ�ǰ��¼��area�����ֵ�ˣ�ֻ��ͨ���ƶ�i���ҵ��µĿ��ܵĸ��������

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int areaRes = (min(height[i], height[j])) * (j-i);
        while(i < j){
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
            int curArea = (min(height[i], height[j])) * (j-i);
            areaRes = (areaRes > curArea) ? areaRes : curArea;
        }

        return areaRes;
    }
};
