// O(n)的复杂度。保持两个指针i,j；
// 分别指向长度数组的首尾。
// 如果ai 小于aj，则移动i向后（i++）。
// 反之，移动j向前（j--）。
// 如果当前的area大于了所记录的area，替换之。
// 这个想法的基础是，如果i的长度小于j, 无论如何移动j，短板在i，
// 不可能找到比当前记录的area更大的值了，只能通过移动i来找到新的可能的更大面积。

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
