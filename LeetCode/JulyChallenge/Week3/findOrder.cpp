class Solution {
public:
    bool visit(int i, vector<int>& visited, vector<int>& res, vector<vector<int>>& adj) {
        if(visited[i] == -1)
            return true;
        
        visited[i] = -1;
        
        for(auto edge: adj[i])
            if(visited[edge] != 1 && visit(edge, visited, res, adj))
                return true;
        res.push_back(i);
        
        visited[i] = 1;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerqsts) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> res;
        vector<int> visited(numCourses, 0);
        
        for(auto i: prerqsts)
            adj[i[0]].push_back(i[1]);
        
        for(int i=0; i<numCourses; i++)
            if(!visited[i] && visit(i, visited, res, adj))
                return {};
        return res;
    }
};
