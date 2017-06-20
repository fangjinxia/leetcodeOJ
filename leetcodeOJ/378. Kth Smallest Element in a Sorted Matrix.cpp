class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            int num = 0;
            for(int i = 0; i < n; ++i){
                int tmp = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += tmp;
            }
            
            if(num < k)
                low = mid+1;
            else
                high = mid;
        }
        
        return low;
    }
};