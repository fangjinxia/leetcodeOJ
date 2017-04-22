class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        
        int i = 0;
        for(int j = 0; i < ransomNote.length() && j < magazine.length(); ){
            if(ransomNote[i] == magazine[j])
                i++; 
            j++;
        }
        return (i == ransomNote.length()) ? true : false;
    }
};