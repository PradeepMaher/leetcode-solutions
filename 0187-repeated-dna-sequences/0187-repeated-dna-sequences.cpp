class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        unordered_map<string, int> mp;
        vector<string> ans;

        for (int i = 0; i + 10 <= n; i++) {
            string curr = s.substr(i, 10);

            mp[curr]++;

            if (mp[curr] == 2) {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};