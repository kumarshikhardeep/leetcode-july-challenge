class Solution {
public:
//     int waterSides(vector<vector<int>> grid, int i, int j){
//         int sides = 0;
//         if(i==0 || grid[i-1][j]==0)
//             sides++;
//         if(i==grid.size()-1 || grid[i+1][j]==0)
//             sides++;
//         if(j==0 || grid[i][j-1]==0)
//             sides++;
//         if(j==grid[0].size()-1 || grid[i][j+1]==0)
//             sides++;
//         return sides;
//     }
    
//     int findPerimiter(vector<vector<int>> grid, int i, int j){
//         int perimiter = 0;
//         stack<pair<int,int>> cur;
//         set<pair<int,int>> visited;
//         cur.push(make_pair(i, j));
//         while(!cur.empty()){
//             pair p = cur.top();
//             cur.pop();
//             i = p.first;
//             j = p.second;
//             if(visited.find(p) == visited.end()){
//                 perimiter += waterSides(grid, i, j);
//                 visited.insert(p);
//             }
            
//             if(i>0 && grid[i-1][j]!=0 && visited.find(make_pair(i-1, j))==visited.end())
//                 cur.push(make_pair(i-1, j));
//             if(i<grid.size()-1 && grid[i+1][j]!=0 && visited.find(make_pair(i+1, j))==visited.end())
//                 cur.push(make_pair(i+1, j));
//             if(j>0 && grid[i][j-1]!=0 && visited.find(make_pair(i, j-1))==visited.end())
//                 cur.push(make_pair(i, j-1));
//             if(j<grid[0].size()-1 && grid[i][j+1]!=0 && visited.find(make_pair(i, j+1))==visited.end())
//                 cur.push(make_pair(i, j+1));
            
//         }
//         return perimiter;
//     }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimiter = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    perimiter += 4;
                    if(i != 0 && grid[i-1][j] == 1)
                        perimiter -= 2;
                    if(j != 0 && grid[i][j-1] == 1)
                        perimiter -= 2;
                    
                }
            }
        }
        return perimiter;
        
        
        
        
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid[0].size(); j++){
//                 if(grid[i][j] == 1)
//                     return findPerimiter(grid, i, j);
//             }
//         }
//         return 0;
    }
};
