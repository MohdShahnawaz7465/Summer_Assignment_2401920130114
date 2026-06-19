class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        
        long long max_sum = current_sum;
        
        
        int n = static_cast<int>(nums.size()); 
        
        for (int i = k; i < n; ++i) {
            current_sum += nums[i] - nums[i - k];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        return static_cast<double>(max_sum) / k;
    }
};
