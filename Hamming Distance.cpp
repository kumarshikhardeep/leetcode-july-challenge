class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x^y;
        int t = 32;
        int count = 0;
        while(t--){
            if(res&1)
                count++;
            res = res>>1;
        }
        return count;
    }
};
