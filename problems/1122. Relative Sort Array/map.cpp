class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> outersect;
        set<int> exist;
        map<int, int> m;
        for(int i=0; i<arr2.size(); i++) {
            exist.insert(arr2[i]);
        }
        for(int i=0; i<arr1.size(); i++) {
            if(exist.find(arr1[i]) == exist.end()) {
                outersect.push_back(arr1[i]);
                continue;
            }
            m[arr1[i]]++;
        }
        for(int i=0; i<arr2.size(); i++) {
            for(int j=0; j<m[arr2[i]]; j++) {
                ans.push_back(arr2[i]);
            }
        }
        sort(outersect.begin(), outersect.end());
        ans.insert(ans.end(), outersect.begin(), outersect.end());
        return ans;
    }
};