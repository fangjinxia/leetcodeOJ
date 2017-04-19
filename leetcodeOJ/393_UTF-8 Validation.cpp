class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        
        for(int i = 0; i < n; i++){
            //1 byte
            if(data[i] >= 0 && data[i] <= 127){
                continue;
            }
            else if(data[i] >= 248 || data[i] < 192)
                return false;
            //2 byte
            int idx = i;
            if(data[i] >= 192){
                idx++;
                if(data[idx] < 128 || data[idx] >= 192)
                    return false;
                cout <<idx <<endl;
                
            }
            //3 byte
            if(data[i] >= 224){
                idx++;
                if(data[idx] < 128 || data[idx] >= 192)
                    return false;
                cout <<idx <<endl;
            }
            //4 byte
            if(data[i] >= 240){
                idx++;
                if(data[idx] < 128 || data[idx] >= 192)
                    return false;
                cout <<idx <<endl;
            }
            i = idx;
        }
        return true;
    }
};