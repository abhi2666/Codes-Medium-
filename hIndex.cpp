class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        int h = 0;
        while(h < n && c[h] > h) h++;
        return h;
    }
};