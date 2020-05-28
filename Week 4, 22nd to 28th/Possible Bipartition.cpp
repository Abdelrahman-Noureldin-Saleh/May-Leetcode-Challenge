class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1, vector<int>());
        for (int i = 0; i < dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> visited(N+1, 0);
        for (int i = 1; i <= N; i++){
            if (visited[i])
                continue;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()){
                int node = q.front(); q.pop();
                for (int j = 0; j < graph[node].size(); j++){
                    if (visited[node] == visited[graph[node][j]])
                        return false;
                    else if (!visited[graph[node][j]]){
                        q.push(graph[node][j]);
                        visited[graph[node][j]] = -visited[node];
                    }
                }
            }
        }
        return true;
        
    }
};