class Solution {
    public:
        int numberOfSubstrings(string s) {
            int set[3] = {0, 0, 0};
            int n = s.length(), l = 0, ans = 0, have = 0;
    
            for (int r = 0; r < n; r++) {
                int index = s[r] - 'a';
                if (set[index] == 0) have++;
                set[index]++;
    
                while (have == 3) {
                    ans += n - r;  // Correctly counts all valid substrings
                    index = s[l] - 'a';
                    set[index]--;
                    if (set[index] == 0) have--;
                    l++;
                }
            }
    
            return ans;
        }
    };
    