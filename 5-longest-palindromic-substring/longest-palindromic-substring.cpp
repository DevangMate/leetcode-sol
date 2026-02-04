class Solution {
public:
int expandFromCenter(const string& s, int left, int right) {
        // Expand while characters match and within bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;

    // Iterate through each character as center
    for (int center = 0; center < s.length(); center++)
    {
        // Expand around odd length palindrome
        int lenOdd = expandFromCenter(s, center, center);
        // Expand around even length palindrome
        int lenEven = expandFromCenter(s, center, center + 1);
        // Get the max of both lengths
        int maxLen = max(lenOdd, lenEven);

        // Update the longest palindrome boundaries
        if (maxLen > end - start)
        {
            start = center - (maxLen - 1) / 2;
            end = center + maxLen / 2;
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, end - start + 1);
    }
};