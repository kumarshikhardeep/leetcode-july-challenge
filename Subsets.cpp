class Solution {
public:
    
    void getSubsets(vector<int> nums, vector<vector<int>> &res, vector<int> &temp, int index){
    
        res.push_back(temp);
        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            getSubsets(nums, res, temp, i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        getSubsets(nums, res, temp, 0);
        return res;
    }
};
