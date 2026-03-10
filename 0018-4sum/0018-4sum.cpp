class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Changed to long long to prevent implicit casting issues
                unordered_set<long long> s; 

                for (int k = j + 1; k < n; k++) {
                    // Cast the first number to long long to prevent overflow during addition
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long last = (long long)target - sum;

                    if (s.find(last) != s.end()) {
                        // Cast 'last' back to int since we know it exists in 'nums'
                        vector<int> curr = {nums[i], nums[j], nums[k], (int)last}; 
                        sort(curr.begin(), curr.end());

                        result.insert(curr);
                    }
                
                    s.insert(nums[k]);
                }
            }
        } 

        return vector<vector<int>>(result.begin(), result.end());    
    }
};