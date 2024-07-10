class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int size_longest = 0;
            int n = s.size();

            int start = 0;
            int end = 0;
            unordered_set<char> window;

            while (end < n) {
                char current = s[end];
                if (window.find(current) == window.end()) {
                    window.insert(current);
                    size_longest = max(size_longest, end - start + 1);
                    end++;
                } else {
                    window.erase(s[start]);
                    start++;
                }
            }

            return size_longest;
        }

    };
