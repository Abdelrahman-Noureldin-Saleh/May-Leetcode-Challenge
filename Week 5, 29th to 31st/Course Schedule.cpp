class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for (vector<int>& req : prerequisites){
            graph[req[1]].push_back(req[0]);
            inDegree[req[0]]++;
        }
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                st.push(i);
        int ans = 0;
        while (!st.empty()){
            int course = st.top(); st.pop();
            ans++;
            for (int i = 0; i < graph[course].size(); i++){
                if (--inDegree[graph[course][i]] == 0)
                    st.push(graph[course][i]);
            }
        }
        return ans == numCourses;
    }
};