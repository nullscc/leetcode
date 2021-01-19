class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        /* 
            贪心策略: 能找到cost为0的移动方法，绝对不找cost为1的方法
            只有两种可能: 最后移动到奇数位置还是偶数位置
            最后移动到奇数位置上，那么有消耗的就只有偶数位置，而且在偶数位置上的每个硬币cost为1，在奇数位置cost为0
            所以如果最后移动到奇数位置上，那么只要统计出偶数位置的硬币的个数计科
        */
        int odd=0, even=0;
        for(int i=0; i<position.size(); i++) {
            if(position[i]%2 == 0) even++;
            else odd++;
        }
        
        return min(odd, even);
    }
};