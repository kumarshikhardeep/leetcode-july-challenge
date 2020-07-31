class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({0});
        int goal = graph.size()-1;
        
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int lastNode = t[t.size()-1];
            if(lastNode == goal){
                res.push_back(t);
            }
            else{
                vector<int> neighbor = graph[lastNode];
                for(int i=0; i<neighbor.size(); i++){
                    vector<int> v = t;
                    v.push_back(neighbor[i]);
                    q.push(v);
                }
            }
        }
        return res;
    }
};
