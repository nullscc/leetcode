class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in_degree(N, 0);
        vector<int> out_degree(N, 0);
        for(int i=0; i<trust.size(); i++) {
            in_degree[trust[i][1]-1]++;
            out_degree[trust[i][0]-1]++;
        }
        for(int i=0; i<N; i++) {
            if(in_degree[i] == (N-1) && out_degree[i] == 0) return i+1;
        }
        return -1;
    }
};