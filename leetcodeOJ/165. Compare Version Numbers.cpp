class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j =0;
        while(i < version1.length() || j < version2.length()){
            int v1 = 0; 
            int v2 = 0;
            
            while(version1[i] != '.' && i < version1.length()){
                v1 *= 10;
                v1 += version1[i] - '0';
                ++i;    
            }
            ++i;
            
            while(version2[j] != '.' && j < version2.length()){
                v2 *= 10;
                v2 += version2[j] - '0';
                ++j;    
            }
            ++j;
            
            if(v1 > v2)
                return 1;
            else if(v1 < v2)
                return -1;
        }
        
        return 0;
    }
};