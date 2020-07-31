class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        long long int tot = 0;
        int res = 0;
        while(tot<=n){
            tot+=i++;
            res++;
        }
        return res-1;
    }
};
