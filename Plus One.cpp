class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        if(l == 0){
            vector<int> v(1);
            v[0] = 1;
            return v;
        }
        if(digits[l-1] < 9){
            digits[l-1] += 1;
            return digits;
        }
        int carry = 1;
        for(int i=l-1; i>=0; i--){
            if(carry + digits[i] == 10){
                digits[i] = 0;
            }
            else{
                digits[i] += carry;
                carry = 0;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
