class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //找到距离最小的元素
        vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), x);
        if(abs(*it - x) > abs(*(it-1) - x)){
            --it;
        }
        
        int lo = (it - arr.begin() <= 0) ? 0 : it - arr.begin();
        int hi = lo;
        while(hi-lo+1 < k){    
            if(lo == 0){
                ++hi;
                continue;
            }
            if(hi == arr.size()-1){
                --lo;
                continue;
            }
            
            if(abs(x - arr[lo-1]) > abs(arr[hi+1] - x)){
                ++hi;
            }
            else{
                --lo;
            }
        }
        
        cout << lo << " " << hi << endl;
        vector<int> res;
        res.assign(arr.begin()+lo, arr.begin()+hi+1);
        return res;
    }
};