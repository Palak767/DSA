class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) p1.push_back({r, c});
                if (img2[r][c] == 1) p2.push_back({r, c});
            }
        }
        map<pair<int, int>, int> countMap;
        int maxOverlap = 0;
        for (auto& a : p1) {
            for (auto& b : p2) {
                pair<int, int> shift = {b.first - a.first, b.second - a.second};
                countMap[shift]++;
                maxOverlap = max(maxOverlap, countMap[shift]);
            }
        }
        return maxOverlap;
    }
};