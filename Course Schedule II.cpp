class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<int> res;
         vector<vector<int> > graph(numCourses, vector<int>(0));
         vector<int> in(numCourses, 0);
         for (int i=0; i<prerequisites.size(); i++) {
             graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
             ++in[prerequisites[i]  [0]];
         }
         queue<int> q;
         for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) 
                q.push(i);
         }
         while (!q.empty()) {
             int t = q.front();
             res.push_back(t);
             q.pop();
             for (int i=0; i<graph[t].size(); i++) {
                 --in[graph[t][i]];
                 if (in[graph[t][i]] == 0) 
                     q.push(graph[t][i]);
             }
         }
         if (res.size() != numCourses) res.clear();
         return res;
        
//         vector<vector<int>> v(numCourses);
//         set<int> finished;
//         vector<int> res;
//         for(int i=0; i<prerequisites.size(); i++){
//             v[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         for(int i=0; i<v.size(); i++){
//             if(v[i].size()==0 && finished.find(i) == finished.end()){
//                 res.push_back(i);
//                 finished.insert(i);
//             }
//             else{
                
//                 for(int j=0; j<v[i].size(); j++){
//                     if(finished.find(v[i][j]) != finished.end() && finished.find(i) != finished.end())
//                         return {};  
//                     if(finished.find(v[i][j]) == finished.end()){
//                         res.push_back(v[i][j]);
//                         finished.insert(v[i][j]);
//                     }
//                 }
//                 if(finished.find(i) == finished.end()){
//                     res.push_back(i);
//                     finished.insert(i);
//                 }
//             }   
//         }
//         return res;
    }
};
