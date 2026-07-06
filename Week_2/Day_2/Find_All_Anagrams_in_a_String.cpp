class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) return ans;

        vector<int> need(26, 0), window(26, 0);

        for (char c : p) {
            need[c - 'a']++;
        }

        int m = p.size();

        for (int i = 0; i < s.size(); i++) {
            window[s[i] - 'a']++;

            if (i >= m) {
                window[s[i - m] - 'a']--;
            }

            if (i >= m - 1 && window == need) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};
