class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(), J.end());
        int ans = 0;
        for (auto &x : S)
            if (s.find(x) != s.end())
                ans++;
        return ans;
    }
};