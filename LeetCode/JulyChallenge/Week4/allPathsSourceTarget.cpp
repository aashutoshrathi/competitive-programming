class Solution {
public:
    int end;
    vector<vector<int>> paths;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int it) {
        path.push_back(it);
        if (it == end)
            paths.push_back(path);
        else 
            for(int node: graph[it])
                dfs(graph, node);
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        end = graph.size() - 1;
        dfs(graph, 0);
        return paths;
    }
};