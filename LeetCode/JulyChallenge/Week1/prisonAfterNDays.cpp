class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp(8);
        vector<vector<int>> visited;
        int j = 0, max_val = 1 << 6;
        while(N-- && j < max_val) {
            j++;
            int n = visited.size();
            for(int i=1; i<7; i++) {
                temp[i] = cells[i-1] == cells[i+1];
            }
            if (n && visited.front() == temp) 
                return visited[N % n];
            cells = temp;
            visited.push_back(cells);
        }
        return cells;
    }
};
