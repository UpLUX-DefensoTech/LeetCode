class Solution {
public:
    void fun(int ind, vector<int> ds, vector<int> nums, int n, vector<vector<int>>& ans, int target){
        if(ind == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
            
        }
        if(nums[ind] <= target){
            ds.push_back(nums[ind]);
            fun(ind, ds, nums, n, ans, target-nums[ind]);
            ds.pop_back();
        }
        
        fun(ind+1, ds,nums, n, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size(), ind = 0;
        vector<int> ds;
        vector<vector<int>> ans;
        fun(ind,ds,candidates,n,ans,target);
        return ans;
    }
};