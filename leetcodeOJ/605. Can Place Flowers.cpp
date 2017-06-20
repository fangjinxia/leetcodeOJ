class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
            return true;
        
        int m = flowerbed.size();
        for(int i = 0; i < m; ++i){
            if(flowerbed[i] == 0 && (i < (m-1)) && flowerbed[i+1] == 1)
                flowerbed[i] = 1;
            else if(flowerbed[i] == 1){
                while(i < m-1){
                    ++i;
                    if(flowerbed[i] == 0)
                        break;
                }
                flowerbed[i] = 1;
            }
        }
        // for(int i = 0; i < m; ++i)
        //     cout << flowerbed[i] << endl;
          
        for(int i = 0; i < m; ++i){
            if(flowerbed[i] == 0){
                flowerbed[i] = 1;
                if(i < m-1){
                    flowerbed[i+1] = 1;
                    
                }
                --n;
                if(n == 0)
                    return true;
            }
        }
        return false;
    }
};