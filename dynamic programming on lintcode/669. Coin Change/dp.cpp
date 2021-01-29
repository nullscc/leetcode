// f[amount] = min(f[amount-a[i]]+1) (a[i]表示所有的硬币选择)

class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        // write your code here
        vector<int>f(amount+1, 10001);
        f[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(auto coin: coins) {
                if(i-coin < 0) continue;
                f[i] = min(f[i-coin]+1, f[i]);
            }
        }
        if(f[amount] == 10001) return -1;
        return f[amount];
    }
};