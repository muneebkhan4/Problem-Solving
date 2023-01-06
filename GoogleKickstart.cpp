#include<bits/stdc++.h>
using namespace std;

int main(){
    int tests=0;
    cin>>tests; // number of test cases
    
    for(int i=0;i<tests;i++){
        // input stream
        int n=0,k=0;
        string str;
        cin>> n;
        cin>> k;
        cin>>str;
        
        // algo
        int x = 0;
        for(int j = 0; j < str.size() / 2; j++) {
            if(str[j] != str[str.size() - j - 1]) {
                x++;
            }
        }
        if(x == k)
            k = 0;
        else if(x > k)
            k = x - k;
        else 
            k = k - x;
        
        // output stream
        
        cout<<"Case #"<<i+1<<": "<<k<<endl;
    }

    return 0;
}
