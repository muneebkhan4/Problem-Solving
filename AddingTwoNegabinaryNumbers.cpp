class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int l= max(arr1.size(),arr2.size())+2;    // carry can be forwarded to maximum 2 positions. 
        int a1,a2,sum, carry=0,r;
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        
        for(int i=0; i<l;i++){
            a1 = i<arr1.size() ? arr1[i] : 0;
            a2 = i<arr2.size() ? arr2[i] : 0; 
            sum = a1+a2+carry;
            r= sum%(-2);
            carry= sum/ (-2);
            if(r<0){
                r+=abs(-2);
                carry =carry+1;
            }
            ans.push_back(r);
        }
        while(ans.back()==0&&ans.size()!=1)
            ans.pop_back();     // remove trailing zeroes 
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

// 12 42

// -2^4 -2^3 -2^2 -2^1 -2^0  = 16-8+4-2+1 = 11
// -2^2 -2^0 = 5

//  1 1 1 1 1
//      1 0 1
//1 0 0 0 0 0
