#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int tests=0;
    cin>>tests; // number of test cases
    vector<string> input;
    for(int i=0;i<tests;i++){
        // input stream
        string str;
        cin>>str;       
        input.push_back(str);
    }
    for(int i=0;i<tests;i++){
        string even, odd;
        for(int j=0;j<input[i].length();j++){
            if(j%2==0){
                even.push_back(input[i][j]);
            }
            else{
                odd.push_back(input[i][j]);                
            }
        }
        // output stream
        cout<<even<<" "<<odd<<endl;
    }
    
    
    return 0;
}
