class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return true;
        if(n == 0)
            return false;
        if(stones[1] != 1)
            return false;
        if(n == 2)
            return true;
            
        for(int i = 0; i < n; i++){
            if(i > 3 && (stones[i] > stones[i-1]*2))
                return false;
        }
        int cur = 1;//当前位置
        int k = 1;//上一次跳的步数
        return isCanCross(stones, stones[n-1], cur, k);
    }
    
    bool isCanCross(vector<int>& stones, int last, int cur, int k){
        if((cur+k-1 == last) || (cur+k == last) || (cur+k+1 == last))
            return true;
            
        vector<int>::iterator iter;
        int num = cur+k+1;
        iter = find(stones.begin(), stones.end(), num);
        if(iter != stones.end()){
            if(isCanCross(stones, last, num, k+1))
                return true;
        }
        
        num = cur+k;
        iter = find(stones.begin(), stones.end(), num);
        if(iter != stones.end()){
            if(isCanCross(stones, last, num, k))
                return true;
        }
        
        if(k > 1){
            num = cur+k-1;
            iter = find(stones.begin(), stones.end(), num);
            if(iter != stones.end()){
                if(isCanCross(stones, last, num, k-1))
                    return true;
            }
        }
        return false;
    }
};