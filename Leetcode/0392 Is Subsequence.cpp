class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0, tIdx = 0;
        while (sIdx < s.size() && tIdx < t.size()) {
            if (s[sIdx] == t[tIdx]) ++sIdx;
            ++tIdx;
        }
        return sIdx == s.size();
    }
};
