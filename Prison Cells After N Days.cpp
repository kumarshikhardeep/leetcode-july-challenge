class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map <int, vector <int> > m;
      if(N == 0) return cells;
      set <vector <int> > visited;
      visited.insert(cells);
      for(int i = 1; i<=14 ; i++ ){
         vector <int> temp(8);
         for(int j = 1; j < 7; j++){
            if((cells[j - 1] ^ cells[j + 1]) == 0){
               temp[j] = 1;
            }
         }
         cells = temp;
         m[i] = temp;
         visited.insert(temp);
      }
      N = N%14;
      return m[N == 0? 14 : N ];
        
        
        
        
        
//         vector<int> temp(8,0);
//         set<vector<int>> visited;
//         unordered_map<int, vector<int>> um;
//         visited.insert(cells);
//         // um[0] = cells;
//         int count = 1;
//         while(count <= N){
//             temp[0] = 0;
//             temp[7] = 0;
//             for(int i = 1; i<7; i++){
//                 if(cells[i-1] == cells[i+1]){
//                     temp[i] = 1;
//                 }
//                 else{
//                     temp[i] = 0;
//                 }
//             }
//             um[count] = temp;
//             if(visited.find(temp) == visited.end()){
//                 visited.insert(temp);
//             }
//             else{
//                 break;
//             }
//             swap(cells, temp);
//             count++;
//         }
//         for(auto i=um.begin(); i!= um.end(); i++){
//             cout<<i->first<<"  ";
//             for(int j=0; j<i->second.size(); j++){
//                 cout<<i->second[j]<<" ";
//             }
//             cout<<"\n";
//         }
//         cout<<count;
//         N = N%(count-1);
        
//         return um[N==0?count-1:N];
    }
};
