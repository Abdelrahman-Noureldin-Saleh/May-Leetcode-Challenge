class Solution {
public:
    bool equal(int arr1[], int arr2[]){
        for (int i = 0; i < 26; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if (n == 0 || m == 0 || n < m) return ans;
        int anagram[26] = {0};
        int current[26] = {0};
        for (int i = 0; i < m; i++) anagram[p[i]-'a']++;
        for (int i = 0; i < m; i++) current[s[i]-'a']++;
        if (equal(anagram, current)) ans.push_back(0);
        for (int i = m; i < n; i++){
            current[s[i]-'a']++, current[s[i-m]-'a']--;
            if (current[s[i]-'a'] == anagram[s[i]-'a'] && current[s[i-m]-'a'] == anagram[s[i-m]-'a'] && equal(anagram, current))    ans.push_back(i-m+1);
        }
        return ans;
    }
};