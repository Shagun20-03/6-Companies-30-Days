class Solution {
public:
    int rev(int i){
        int j=0;
        while(i>0){
            j=j*10+(i%10);
            i=i/10;
        }
        return j;
    }
    int countNicePairs(vector<int>& nums) {
        int res=0, mod=1e9+7;
        unordered_map<int, int>count;
        for(int &i:nums){
            res=(res+count[i-rev(i)]++)%mod;
        }
        return res;
    }
};
