class Solution {
public:
    //二分法
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 1; i <= m; ++i) {
                //cnt记录小于等于mid的数值的数目
                cnt += (mid / i <= n) ? (mid / i) : n;
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};