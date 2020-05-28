class Solution {
public:
    string frequencySort(string s) {
        map<char, int> map;
        for (int i = 0; i < s.size(); i++) map[s[i]]++;
        
        vector<pair<int, char>> vec;
        
        for (auto &it : map)
            vec.push_back(make_pair(it.second, it.first));
        
        sort(vec.begin(), vec.end());
        
        stringstream ss;
        for (int i = vec.size()-1; i >= 0; i--)
            ss << string(vec[i].first, vec[i].second);
        
        return ss.str();
        
    }
};