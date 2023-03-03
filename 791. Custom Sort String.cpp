class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        string res;
        for (char c : order) {
            if (freq.count(c)) {
                res += string(freq[c], c);
                freq.erase(c);
            }
        }
        for (auto p : freq) {
            res += string(p.second, p.first);
        }
        return res;
    }
};

// chatGPT solution 😑😑