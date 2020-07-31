class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i=0; i<tasks.size(); i++){
            count[tasks[i]-'A']++;
        }
        
        sort(count.begin(), count.end(), greater());
        
        int time = 0;
        while(count[0]>0){
            int i = 0;
            while(i<=n){
                if(count[0]==0)
                    break;
                
                if(i<26 && count[i]>0){
                    count[i]--;
                }
                
                time++;
                i++;
            }
            sort(count.begin(), count.end(), greater());
        }
        return time;
    }
};
