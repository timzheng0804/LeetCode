class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> index;
        vector<int> sv(26, 0), pv(26, 0);
        for (int i = 0; i < p.length(); ++i) {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }
        if (pv == sv) {
            index.push_back(0);    
        }
        for (int i = p.size(); i < s.size(); ++i) {
            sv[s[i] - 'a']++;
            sv[s[i - p.size()] - 'a']--;
            
            if (sv == pv) {
                index.push_back(i - p.size() + 1);
            }
        }
        return index;
    }
};