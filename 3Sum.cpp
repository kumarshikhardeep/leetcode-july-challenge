class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
      
      int total = nums.size(); 
      
      sort(nums.begin(), nums.end());
      
      for (int firstNumIdx = 0; firstNumIdx < total; ++firstNumIdx) {
        int firstNum = nums[firstNumIdx];
        int start = firstNumIdx + 1;
        int end = total - 1;
        while (start < end) {
          int current = nums[start] + nums[end];
          if (current < -firstNum) {
            ++start;
          } else if (current > -firstNum) {
            --end;
          } else {
            res.push_back({firstNum, nums[start], nums[end]});
            int oldStart = start;
            int oldEnd = end;
            while (start < end && nums[start] == nums[oldStart]) {
              ++start;
            }
            while (end > start && nums[end] == nums[oldEnd]) {
              --end;
            }
          }
          while (firstNumIdx + 1 < total 
                 && nums[firstNumIdx + 1] == nums[firstNumIdx]) {
            ++firstNumIdx;
          }
        }
      }
      
      return res;
        
    }
};
