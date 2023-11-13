/*
return two indexes 1 based whose values adds up to the target
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size()-1;
        int sum = 0;
        vector<int>ans;
        while(l <= h){
            sum = (numbers[l] + numbers[h]);
            if(sum == target){
                ans.push_back(l+1);
                ans.push_back(h+1);
                return ans;
            }
            else if(sum > target) h--;
            else l++;
        }
        return ans;
    }
    
};