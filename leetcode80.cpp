/*
From each element, check for the element two positions behind it and
if not equal then that is good..
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto ele : nums){
            if(i == 0 || i == 1 || nums[i-2] != ele){
                // pick the elements in these cases only
                nums[i++] = ele;
            }
        }
        return i;
    }
};