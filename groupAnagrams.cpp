class Solution {
public:
    bool isEqual(string a, string b){
        int count =0;
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length() && a[i]!='\0';j++){
                if(a[i]==b[j]){
                    b[j]='\0';
                    a[i]='\0';
                    count++;
                }
            }    
        }
        if(count==a.length() && count==b.length())
            return true;
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res={{strs[0]}};
        for(int i=1;i<strs.size();i++){
            bool present = false;
            for(int j=0;j<res.size() && !present;j++){
                if(isEqual(res[j][0], strs[i])){
                    res[j].push_back(strs[i]);
                    present = true; 
                }
            }
            if(!present){
                vector<string> tmp;
                tmp.push_back(strs[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// 11 14  11 42
