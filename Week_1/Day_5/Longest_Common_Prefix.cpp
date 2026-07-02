class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string firstStrs = strs[0];
        for (int i = 0; i < firstStrs.size(); i++) {
            char c = firstStrs[i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return firstStrs.substr(0, i);
                }
            }
        }
        return firstStrs;
    }
};
