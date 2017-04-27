class Solution {
public:
    bool validIPv4(string IP){
        if(IP[IP.size()-1] == '.')
            return false;
        const string token = "0123456789";
        int idx = 0;
        for(int i = 0; i < 4; i++){
            int k = IP.find('.', idx);
            if(i == 3 && k != string::npos)
                return false;
            string str = "";
            if(k == string::npos)
                str = IP.substr(idx);
            else
                str = IP.substr(idx, k-idx);
            
            if(str.size() <= 0 || str.size() > 3)
                return false;
            if(str.size() != 1 && str[0] == '0')
                return false;
            for(int j = 0; j < str.size(); j++){
                if(token.find(str[j]) == string::npos)
                    return false;
            }
            int num = atoi(str.c_str());
            if(num < 0 || num > 255)
                return false;
            idx = k+1;
        }
        return true;
    }
    
    bool validIPv6(string IP){
        if(IP[IP.size()-1] == ':')
            return false;
        const string token = "0123456789abcdefABCDEF";
        int idx = 0;
        for(int i = 0; i < 8; i++){
            int k = IP.find(':', idx);
            if(i == 7 && k != string::npos)
                return false;
            string str = "";
            if(k == string::npos){
                str = IP.substr(idx);
            }
            else{
                str = IP.substr(idx, k-idx);
            }
            
            if(str.size() <= 0 || str.size() > 4)
                return false;
            for(int j = 0; j < str.size(); j++){
                if(token.find(str[j]) == string::npos)
                    return false;
            }
            idx = k+1;
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        //IPv4
        if(IP.find('.') != string::npos)
            if(validIPv4(IP))
                return "IPv4";
        //IPv4
        if(IP.find(':') != string::npos)
            if(validIPv6(IP))
                return "IPv6";
                
        return "Neither";
    }
};