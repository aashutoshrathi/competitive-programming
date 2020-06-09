class Solution {
public:
    int f(int x) {
        return x-1;
    }
    
    // check all connected nodes
    bool visitNeighbours(vector<vector<int>>& adjList, vector<int>& part, int v, int color) {
        if(part[v] != -1)
            return part[v] == color;
        else
            part[v] = color;
        
        for(int i: adjList[v])
            if(!visitNeighbours(adjList, part, i, !color))
                return false;
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(N, vector<int>());
        vector<int> part(N, -1); // -1 for not visited and 0, 1 are colors.
        
        int dColor = 0;
        
        // Make edges using adjacency list
        for(auto i: dislikes)
            for(int j=0; j<=1; j++)
                adjList[f(i[j])].push_back(f(i[!j]));
        
        // explore only not visited ones and do DFS in them
        for(int i=0; i<N; i++)
            if(part[i] == -1 && !visitNeighbours(adjList, part, i, dColor))
                return false;
        
        return true;
    }
};

