class Solution {
public:
    
//     void getSentences(string s, unordered_map<string, int> umap, vector<string>& res, int index, string temp){
//         // cout<<index<<"\n";
//         if(index == s.size()){
//             // cout<<"S\n";
//             res.push_back(temp);
//             return;
//         }
        
//         for(int i=index; i<s.size(); i++){
//             if(umap.find(s.substr(index, i-index+1)) != umap.end()){
//                 // cout<<"A"<<"\n";
//                 string aux = temp.size() == 0 ? temp+s.substr(index, i-index+1) : temp+" "+s.substr(index, i-index+1);
//                 getSentences(s, umap, res, i+1, aux);
//             }
//         }
//     }
    
    vector<string> rec(const string& sentence, const vector<string>& dict,
    unordered_map<string, vector<string>>& found) {
    
    if(found.count(sentence)) {
        return found[sentence];
    }

    int n = sentence.size();
    vector<string> result;
    for(int i = 1; i <= n; i++) {
        string word = sentence.substr(0, i);
        string rem = sentence.substr(i);
        if(find(dict.begin(), dict.end(), word) != dict.end()) {
            if(rem.empty()) {
                result.push_back(word);
            }
            else {
                for(auto& s: rec(rem, dict, found)) {
                    result.push_back(word + " " + s);
                }
            }
        }
    }

    found[sentence] = result;
    return result;
}
    
    vector<string> wordBreak(string A, vector<string>& B) {
        
//         unordered_map<string, int> umap;
//         for(string str:wordDict){
//             umap[str] = 1;
//         }
        
//         vector<string> res;
        
//         string temp = "";
//         int index = 0;
//         getSentences(s,  umap, res, index, temp);
//         return res;
        
        
        
            unordered_map<string, vector<string>> found;
            return rec(A, B, found);
        
        
    }
};
