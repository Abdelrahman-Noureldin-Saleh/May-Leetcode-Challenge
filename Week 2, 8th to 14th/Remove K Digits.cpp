class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> out;
        int m = num.size() - k;
        for (int i = 0; i < num.size(); i++){
            while (!out.empty() && num[i] < out.top() && k)
                out.pop(), k--;
            if (!out.empty() || num[i] != '0')
                out.push(num[i]);
        }
        while (k-- && !out.empty())
            out.pop();
        
        string ans;
        while (!out.empty()){
            ans.push_back(out.top()); out.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};