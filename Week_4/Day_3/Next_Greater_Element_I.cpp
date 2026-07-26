class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }

        return result;
    }
};
