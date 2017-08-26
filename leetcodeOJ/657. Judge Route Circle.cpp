class Solution {
public:
    bool judgeCircle(string moves) {
        int num_of_L = 0;
        int num_of_R = 0;
        int num_of_U = 0;
        int num_of_D = 0;
        
        for(int i = 0; i < moves.length(); ++i){
            if(moves[i] == 'L'){
                ++num_of_L;
            }
            else if(moves[i] == 'R'){
                ++num_of_R;
            }
            else if(moves[i] == 'U'){
                ++num_of_U;
            }
            else{
                ++num_of_D;
            }
        }
        
        if((num_of_L == num_of_R) && (num_of_U == num_of_D))
            return true;
        
        return false;
    }
};