class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        /* 
            实际上代价是: 用numExchange-1个空瓶子换一瓶酒
            所以问题变成: 初始时有numBottles个空瓶子，每numExchange-1空瓶换瓶酒
            即求一个最大的n，使得 numBottles - (numExchange-1)*n < numExchange
            即 n > (numBottles - numExchange)/(numExchange-1) (满足此math式子的最小的n)
            即 n = (numBottles - numExchange)/(numExchange-1) + 1 (c++式子)
            我们最初假设是numBottles个空瓶子，实际上我们已经喝了numBottles瓶酒了
            即答案为: (numBottles - numExchange)/(numExchange-1) + 1 + numBottles;
        */
        if(numBottles < numExchange) return numBottles;

        return (numBottles - numExchange)/(numExchange-1) + 1 + numBottles;
    }
};