class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, sign = 1;
        
        auto it = str.begin();
        
        while (it != str.end() && *it == ' ')
            ++it;
            
        if (it != str.end() && (*it == '-' || *it == '+')) {
            if (*it++ == '-') sign = -1;
        }
        
        while (it != str.end() && *it >= '0' && *it <= '9') {
            int n = *it - '0';
            if (ans > (INT_MAX - n)/10)
                return (sign > 0) ? INT_MAX : INT_MIN;
                
            ans = 10*ans + (*it++ - '0');
        }
        
        return sign*ans;
    }
};
