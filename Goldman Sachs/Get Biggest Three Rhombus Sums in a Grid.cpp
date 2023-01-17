class Solution {
public:
    int n, m;
    bool check(pair<int, int> a){
        return (a.first>=0 && a.first<n && a.second>=0 && a.second<m);
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<long long>s;
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s.insert(grid[i][j]);
            }
        }
        for(int l=1;l<=50;l++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    //all 4 directions
                    pair<int, int>a={i-l, j};
                    pair<int, int>b={i, j-l};
                    pair<int, int>c={i+l, j};
                    pair<int, int>d={i, j+l};
                    if(check(a)==false && check(b)==false && check(c)==false &&                                 check(d)==false)
                        goto end; //comes out of loop
                    if(check(a) && check(b) && check(c) && check(d)) {
                        long long total=(long long)grid[i-l][j]+grid[i+l][j]+grid[i][j-l]+grid[i][j+l];
                        for(int k=1;k<=l-1;k++) total+=(long long)grid[i-k][j-l+k];
                        for(int k=1;k<=l-1;k++) total+=(long long)grid[i-k][j+l-k];
                        for(int k=1;k<=l-1;k++) total+=(long long)grid[i+k][j+l-k];
                        for(int k=1;k<=l-1;k++) total+=(long long)grid[i+k][j-l+k];
                        s.insert(total);
                    }
                }
            }
        }
        end:
        vector<int> ans;
        for(auto i:s){
            ans.push_back(i);
        }
        if(ans.size()<=3){
            reverse(ans.begin(), ans.end());
            return ans;
        }
        vector<int> res;
        res.push_back(ans.back());
        ans.pop_back();
        res.push_back(ans.back());
        ans.pop_back();
        res.push_back(ans.back());
        return res;
    }
};
