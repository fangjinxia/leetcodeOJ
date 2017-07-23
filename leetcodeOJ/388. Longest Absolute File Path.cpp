class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        int cnt = 0, ln = 1;
        bool isFile = false;
        vector<int> level(200);
        level[0] = 0;
        
        for(int i = 0, len = input.length(); i < len; ++i){
            //find which level
            while(input[i] == '\t'){
                ++ln;
                ++i;
            }
            //read file name
            while(input[i] != '\n' && i < len){
                if(input[i] == '.')
                    isFile = true;
                
                ++cnt;
                ++i;
            }
            //calculate
            if(isFile){
                ans = max(ans, level[ln-1]+cnt);
            }
            else{
                level[ln] = level[ln-1]+cnt+1;//1 means '/'                
            }
            
            //reset
            cnt = 0;
            ln = 1;
            isFile = false;
        }
        
        return ans;
    }
};