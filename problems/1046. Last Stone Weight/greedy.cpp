class Solution {
public:
    int get_heaviest(vector<bool> &f, vector<int>& stones) {
        int w=0;
        int ret;
        for(int i=0; i<stones.size(); i++) {
            if(stones[i]>w && f[i]) {
                w = stones[i];
                ret = i;
            }
        }
        f[ret] = false;
        return ret;
    }

    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();
        vector<bool> f = vector<bool>(len, true);

        int i1, i2;
        int m;
        for(int i=0; i<len; i++) {
            i1 = get_heaviest(f, stones);
            i2 = get_heaviest(f, stones);
            if(i1 == i2) {
                m = i2;
                break;
            }
            if(stones[i1] == stones[i2]) {
                stones[i2] = 0;
            }
            else {
                stones[i2] = stones[i1] - stones[i2];
                f[i2] = true;
            }
            m = i2;
        }
        
        return stones[m];
    }
};