class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;
        for(int num:nums){
            xy ^= num;
        }
        
        int lowBit = xy & (-xy);
        
        vector<int> res{0,0};
        for(int num:nums){
            if(lowBit & num){
                res[1] ^= num;
            }
            else{
                res[0] ^= num;
            }
        }
        return res;
    }
};
