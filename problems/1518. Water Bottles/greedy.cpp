class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles, m=0, ret=0;   
        /* 
            n为当前有多少酒可以喝
            m为当前空瓶子数量
            ret为一共喝了多少酒
        */
        // 每次将所有酒喝完，每次将能换的空瓶子全部换完(先喝再换)
        while(n>0 || m>=numExchange) {
            m = m + n;      // 将所有酒喝完
            ret = ret + n;

            n = m / numExchange;      // 能换的空瓶子全部换完
            m = m - n*numExchange; 
        }
        return ret;
    }
};