class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Problem
        int n = nums.size();
    //      for ( int i =0 ; i< n;i++ ){
    //         for (int j = i+1 ; j <n ; j++){
    //             if(nums[i] + nums [j] == target){
    //                 return {i ,j};
    //             }
    //         }
    //      }
    //      return {};
    //  // O [n2]

    //  hashMap method unordered_map 
      std::unordered_map<int,int> seen;
      for (int i =0 ; i <n ; i++){
       // 2 - 9 = 7
       int complement =  target -nums[i];

       if (seen.find(complement) !=  seen.end()){
        return { seen[complement],i};
       } 
       seen[nums[i]] = i;
      }
      return {};

    }
};