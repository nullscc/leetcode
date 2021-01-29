/*
这个有点难理解，主要是位操作有点难懂，不过这个知识点暂时不太重要~
*/
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return (~K & 1) ^ kthGrammar(N-1, (K+1)/2);
    }
};