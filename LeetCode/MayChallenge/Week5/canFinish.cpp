class Solution {
public:
    bool circularDependecy(vector<vector<int>>& dEdges, vector<int>& visited, int node) {
        if(visited[node] == -1)
            return true;
        
        visited[node] = -1;
        
        for(auto edge : dEdges[node]){
            if(visited[edge] != 1 && circularDependecy(dEdges, visited, edge))
                return true;
        }
        
        visited[node] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prqsts) {
        vector<vector<int>> directed_edges(numCourses, vector<int>());
        for(auto i: prqsts) {
            directed_edges[i[0]].push_back(i[1]);
        }
        
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(!visited[i] && circularDependecy(directed_edges, visited, i))
                return false;
        }
        
        return true;
    }
};
