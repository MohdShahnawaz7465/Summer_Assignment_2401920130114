class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        function<void(int, int)> solve = [&](int open, int close) {
            if (current.size() == 2 * n) {
                result.push_back(current);
                return;
            }
            if (open < n) {
                current.push_back('(');
                solve(open + 1, close);
                current.pop_back();
            }
            if (close < open) {
                current.push_back(')');
                solve(open, close + 1);
                current.pop_back();
            }
        };

        solve(0, 0);
        return result;
    }
};
