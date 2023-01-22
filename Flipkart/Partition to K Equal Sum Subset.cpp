
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0, maxNum=0;
        vector<int> visited(nums.size(), 0);
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxNum=max(maxNum, nums[i]);
        }
        if(sum%k!=0 || maxNum>sum/k) //any element greater than sum
            return false;
        return helper(nums, k, sum/k, 0, visited, 0);
    }
    
    private:
    bool helper(vector<int> &nums, int k, int targetSum, int currSum, vector<int> &visited, int ind) {
        if(k==0)
            return true;
        if(currSum>targetSum)
            return false;
        if(currSum==targetSum)
            return helper(nums, k-1, targetSum, 0, visited, 0);
        
        for(int i=ind;i<nums.size();i++){
            if(!visited[i]) {
                visited[i]=1;   //an element should be taken only once
                if(helper(nums, k, targetSum, currSum+nums[i], visited, i+1))
                    return true;
                visited[i]=0;   //backtrack
            }
        }
        return false;
    }
};
