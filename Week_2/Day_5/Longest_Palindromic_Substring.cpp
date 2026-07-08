class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
           
            int len = (right - 1) - (left + 1) + 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < (int)s.size(); i++) {
            expandFromCenter(i, i);      
            expandFromCenter(i, i + 1);  
        }

        return s.substr(start, maxLen);
    }
};
