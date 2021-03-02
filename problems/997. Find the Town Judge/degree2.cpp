/*
    想象每个人手里刚开始都有投票权(可以欠)，投出去一票票数-1，得到一票票数+1
    judge必然是会得到N-1票，而没有损失票
    其他人必然至少投出去一票，又因为每个人最多得到N-1票
    所以只有judge最后得到N-1票
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degree(N, 0);
        for(int i=0; i<trust.size(); i++) {
            degree[trust[i][1]-1]++;
            degree[trust[i][0]-1]--;
        }
        for(int i=0; i<N; i++) {
            if(degree[i] == (N-1)) return i+1;
        }
        return -1;
    }
};