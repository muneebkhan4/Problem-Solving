class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int size = nums.size();
        for(int i=1, j=1;i<size;i++){
            int preVal=nums[i-1];
            int currVal=nums[i];
            j = i+1;
            if(preVal==currVal){
                while(i<size && currVal==nums[i])
                    i++;
            }
            if(i>=j){
                int before = size;
                int diff = i-j;
                size = size - diff;
                int a=i;
                i=j;
               for(;a<before;a++){
                    nums[j] = nums[a];
                    j++;
                }
            }
        }
        cout<<size<<endl;
        return size;
    }
};
// Best solution
// int i = 0;
//     for (int n : nums)
//         if (i < 2 || n > nums[i-2])
//             nums[i++] = n;
//     return i;


// 12 47  1 59
