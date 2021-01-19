class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if(len==0) return false;

        int sum = 0;
        if(len<=2) {
            for(int i=0; i<len; i++) {
                if(flowerbed[i] && n) return false;
            }
            if(n<=1) return true;
            else return false;
        }
        
        if(!flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            sum++;
        }
        for(int i=1; i<len-1; i++) {
            if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1]) {
                flowerbed[i] = 1;
                sum++;
            }
        }

        if(!flowerbed[len-2] && !flowerbed[len-1]) {
            flowerbed[len-1] = 1;
            sum++;
        }
        
        if(sum>=n) return true;
        return false;
    }
};