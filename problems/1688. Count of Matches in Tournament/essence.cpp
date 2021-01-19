class Solution {
public:
    // 没进行一场比赛，淘汰一个队伍，且不存在队伍不去比赛就拿到冠军了
    // 共淘汰n-1个队伍，所以需要进行n-1场比赛
    int numberOfMatches(int n) {
        return n-1;
    }
};