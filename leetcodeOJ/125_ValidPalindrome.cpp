class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size())
            return true;
          
        int n = s.size();
        string str = "";
        for(int i = 0; i < n; i++){
            if(isalpha(s[i]))
                str += tolower(s[i]);
            else if(isdigit(s[i]))
                str += s[i];
            else
                continue;
        }
     //   cout << str <<endl;
        int left = 0;
        int right = str.size()-1;
        for(; left < right; left++, right--){
            //cout << left << right << endl;
            if(str[left] != str[right])
                break;
        }
        
        if(left < right)
            return false;
        else
            return true;
    }
};