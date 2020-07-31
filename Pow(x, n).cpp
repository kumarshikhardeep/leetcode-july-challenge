class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
        double res = x*x;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        if(n==2)
            return res;
        if(n==-2)
            return 1/res;
        
        int sign = n<0?-1:1;
        n = abs(n);
            
        long long int count  = 2;
        while(count<=n){
            
            if(count+count > n){
                break;
            }
            count += count;
            res *= res; 
            
        }
        while(count<n){
            res = res * x;
            count++;
        }
        if(sign == -1)
            return 1/res;
        return res;
    }
};
