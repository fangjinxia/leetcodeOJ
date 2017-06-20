class Solution {
private:
    int res = 0;
    
public:
    int countArrangement(int N) {
        //int res = 0;
        bool mark[N+1] = {false};
        backTrace(N, 1, mark);
        return res;
    }
    
    void backTrace(int N, int k, bool visited[]){
        if(k > N){
            ++res;
            return ;
        }
        
        for(int i = 1; i <= N; ++i){
            if(!visited[i] && isCheck(k, i)){
                visited[i] = true;
                backTrace(N, k+1, visited);
                visited[i] = false;
            }
        }
    }
    
    bool isCheck(int k, int i){
        if((k % i == 0) || (i % k == 0))
            return true;
        return false;
    }
};