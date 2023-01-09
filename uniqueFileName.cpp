class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        // declaration
        vector<string> ans;
        set<string> unique;
        for(int i=0;i<names.size();i++){
            int before = unique.size();
            unique.insert(names[i]);
            if(unique.size()>before){
                ans.push_back(names[i]);
            }
            else{
                int j=1;
                bool flag = true;
                while(flag){
                    string newstr = names[i];
                    newstr = newstr+"(";
                    newstr = newstr+to_string(j);
                    newstr = newstr+")";
                    int before = unique.size();
                    unique.insert(newstr);
                    if(unique.size()>before){
                        ans.push_back(newstr);
                        flag=false;
                    }       
                    j++;
                }
            }
        }
        return ans;
    }
};
// 11 20 , 12 06
