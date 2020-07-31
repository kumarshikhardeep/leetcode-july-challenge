class Solution {
public:
    int nthUglyNumber(int n) {
        int v[n];
        v[0] = 1;
        int l2 = 0;
        int l3 = 0;
        int l5 = 0;
        int a = v[l2]*2;
        int b = v[l3]*3;
        int c = v[l5]*5;
        for(int i=1; i<n; i++){
            
            int t = min(a, min(b, c));
            v[i] = t;
            if(t == a){
                l2++;
                a = v[l2]*2;
            }
            if(t==b){
                l3++;
                b = v[l3]*3;
            }
            if(t==c){
                l5++;
                c  = v[l5]*5;
            }
            
            // cout<<t<< " ";
        }
       return v[n-1];
    }
};
