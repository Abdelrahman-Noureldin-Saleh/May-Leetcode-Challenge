class Solution {
public:
    vector<int> countBits(int num) {
        for (int i = 0; i < 100; i++)
            printf("%d ", __builtin_popcount(i));
        if (num == 0) return vector<int>({0});
        if (num == 1) return vector<int>({0, 1});
        vector<int> ans(num+1, 0);
        ans[1] = 1;
        for (int i = 2; i <= num;){
            int upper = i;
            for (int j = upper/2; j < upper && i <= num; j++)
                ans[i++] = ans[j];
            for (int j = upper/2; j < upper && i <= num; j++)
                ans[i++] = ans[j] + 1;
        }
        return ans;
    }
};