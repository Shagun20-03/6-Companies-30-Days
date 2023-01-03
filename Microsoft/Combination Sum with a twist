class Solution {
    private:
    void findCombination(int n, int k, vector<vector<int>> &ans, vector<int> &temp){
        //base condition
        if(temp.size()==k && n==0){
            ans.push_back(temp);
            return;
        }
        if(temp.size()<k){
            for(int i=temp.empty()?1:temp.back()+1;i<=9;i++){
            //if current element is greater than the sum we want
            if(i>n){
                break;
            }
            temp.push_back(i);
            findCombination(n-i, k, ans, temp);
            temp.pop_back();    //backtrack 
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        findCombination(n, k, ans, temp);
        return ans;
    }
};
