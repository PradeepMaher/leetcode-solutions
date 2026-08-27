class Solution {
public:
    string ans = "";

    bool solve(int pos, string &target, vector<int> &cnt, string &cur) {
        if (pos == target.size()) {
            return false; // Equal to target, not strictly greater
        }

        // First try to keep the same character
        int x = target[pos] - 'a';

        if (cnt[x] > 0) {
            cnt[x]--;
            cur += target[pos];

            if (solve(pos + 1, target, cnt, cur))
                return true;

            cur.pop_back();
            cnt[x]++;
        }

        // Now try the smallest character greater than target[pos]
        for (int c = x + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                cur += char('a' + c);
                cnt[c]--;

                // Once greater, fill the rest in sorted order
                for (int j = 0; j < 26; j++) {
                    while (cnt[j] > 0) {
                        cur += char('a' + j);
                        cnt[j]--;
                    }
                }

                ans = cur;
                return true;
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string cur;

        solve(0, target, cnt, cur);

        return ans;
    }
};