class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int, int>>> graph(n);
        for(auto & road: roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()){
            pair<long long, int> it=pq.top();
            pq.pop();
            
            for(auto &adjNode:graph[it.second]){
                long long vert=adjNode.first;
                long long edge=adjNode.second;
                
                if(dist[vert]>dist[it.second]+edge) {
                    dist[vert]=dist[it.second]+edge;
                    pq.push({dist[vert], vert});
                    path[vert]=path[it.second]%mod;
                }
                else if(dist[vert]==it.first+edge){
                    path[vert]+=path[it.second];
                    path[vert]%=mod;
                }
            }
        }
        return path[n-1];
    }
};
