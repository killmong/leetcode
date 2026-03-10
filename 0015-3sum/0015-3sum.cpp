class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the array so we can use two pointers and easily skip duplicates
        sort(nums.begin(), nums.end());
        
        // 2. Fix the first number (nums[i])
        for (int i = 0; i < n - 2; i++) {
            
            // Skip duplicate values for our fixed number to avoid duplicate answers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 3. Set up the Two Pointers for the remaining elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // We found a valid triplet!
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward to look for other combinations
                    left++;
                    right--;
                    
                } else if (sum < 0) {
                    // Sum is too small, we need a bigger number. Move left pointer up.
                    left++;
                } else {
                    // Sum is too large, we need a smaller number. Move right pointer down.
                    right--;
                }
            }
        }
        
        return result;
    }
};