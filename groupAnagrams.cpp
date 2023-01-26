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




// Best Solution

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
       vector<vector<string>>res;
        
       unordered_map<string, vector<string>>mp;
        
         /*
                Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
                
                After the below opeartion of for loop map will contain
                
                aet -- eat, tea, ate
                ant -- tan, nat
                abt -- bat
        */
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        
        //now simply put the elements  of second column of map in ans
        
        for(auto i : mp)
        {
            res.push_back(i.second);
        }

        return res;
    }
};
// 11 14  11 42
