class Solution {
public:
    int helper(string &s, int i, long long num, int sign) {
        if (i > s.size() || !isdigit(s[i])) {
            return int(sign * num);
        }
        num = num * 10 + (s[i] - '0');
        if (sign * num <= INT_MIN)
            return INT_MIN;
        if (sign * num >= INT_MAX)
            return INT_MAX;
        return helper(s, i + 1, num, sign);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1;

        while (i < s.size() && s[i] == ' ')
            i++;
        if (i == s.size())
            return 0;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } 
        else if (s[i] == '+') {
            i++;
        }
        // while (i < s.size() && isdigit(s[i])) {
        //     int digit = s[i] - '0';

        //     if (res > (INT_MAX - digit) / 10) {
        //         return (sign == -1) ? INT_MIN : INT_MAX;
        //     }
        //     res = res * 10 + digit;

        //     if (sign * res > INT_MAX)
        //         return INT_MAX;

        //     if (sign * res < INT_MIN)
        //         return INT_MIN;

        //     i++;
        // }

        // return (int)(sign * res);
        return helper(s, i, 0, sign);
    }
};