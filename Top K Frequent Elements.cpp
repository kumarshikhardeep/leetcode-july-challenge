class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i]) == um.end())
                um[nums[i]] = 0;
            um[nums[i]] += 1;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for(auto i=um.begin(); i!=um.end(); i++){
            // cout<<i->first<<" "<<i->second<<"\n";
            maxHeap.push(make_pair(i->second, i->first));
        }
         
        vector<int> res;
        while(k--){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
};
