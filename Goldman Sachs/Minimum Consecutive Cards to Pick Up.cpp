class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n=cards.size();
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++) {
            if(mp.find(cards[i])!=mp.end()) {
                ans=min(ans, i-mp[cards[i]]+1);
            }
            //storing index of elements
            mp[cards[i]]=i;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
