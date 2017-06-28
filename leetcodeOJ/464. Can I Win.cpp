class Solution {
public:
    vector<bool> win;
    int choosen = 0;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0)
            return true;
        else if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal)
            return false;
        
       // unordered_map<int, char> m;
        win.resize(1 << maxChoosableInteger);
        //win[maxChoosableInteger] = true;
        return canWin(maxChoosableInteger, desiredTotal, 0);
    }
    
    bool canWin(int maxint, int total, int now){
        if(win[choosen] != 0)
            return win[choosen];
        
        if(now >= total){
            win[choosen] = false;
            return false;
        }
        
        for(int i = 1; i <= maxint; ++i){
            int bit = 1 << (i-1);
            if((choosen&bit) == 0){
                choosen ^= bit;
                bool ulose = !canWin(maxint, total, now+i);
                choosen ^= bit;
                
                if(ulose){
                    win[choosen] = true;
                    return true;
                }
            }
                
        }
        
        win[choosen] = false;
        return false;
    }
    
    
};