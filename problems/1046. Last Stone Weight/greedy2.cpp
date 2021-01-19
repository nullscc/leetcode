class Solution {
public:
    void swap(vector<int>& l, int i, int j) {
        int tmp = l[i];
        l[i] = l[j];
        l[j] = tmp;
    }

    void heap_ajust(vector<int>& heap, int m, int n) {
        int k = m;
        while(2*k<=n) {
            if((2*k+1)>n) {
                if(heap[2*k]>heap[k]) {
                    swap(heap, k, 2*k);
                    k = 2*k;
                } else {
                    break;
                }
            }
            if((2*k+1)<=n) {
                int tmp=2*k;
                if(heap[tmp]<heap[tmp+1]) tmp++;
                if(heap[tmp]>heap[k]) {
                    swap(heap, k, tmp);
                    k = tmp;
                }
                else break;
            }
        }
    }

    void build_heap(vector<int>& heap) {
        int n = heap.size() - 1;

        for(int i=n/2; i>=1; i--) {
            heap_ajust(heap, i, n);
        }
    }
    
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();

        vector<int> heap(stones.size()+1);
        for(int i=1; i<len+1; i++) {
            heap[i] = stones[i-1];
        }
        build_heap(heap);

        int w1, w2;
        int n = len;
        while(n>=1) {
            w1 = heap[1];

            swap(heap, 1, n);
            n--;
            if(n<=0) return w1;
            heap_ajust(heap, 1, n);

            w2 = heap[1];
            if(w1==w2) {
                swap(heap, 1, n);
                n--;
                heap_ajust(heap, 1, n);
            } else {
                heap[1] = w1 - w2;
                heap_ajust(heap, 1, n);
            }

        }
        return 0;
    }
};