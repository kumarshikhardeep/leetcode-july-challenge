class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        for(; start<s.length(); start++){
            if(s[start]!=' ')
                break;
        }
        int end=s.length()-1;
        for(; end>=0; end--){
            if(s[end]!=' ')
                break;
        }
        if(start>end)
            return "";
        string res="";
        int i=end;
        int j=end;
        while(i>start){
            if(s[i] == ' '){
                res += s.substr(i+1, j-i)+" ";
                while(s[i]==' '){
                    i--;
                }
                j=i;
                continue;
            }
            i--;
        }
        res += s.substr(i, j-i+1);
        return res;
    }
};
