int lengthOfLongestSubstring(char* s) {
    int s_len = strlen(s);
    int len = 0;
    int l, r;
    char mark[256] = { 0 };

    for (l = 0, r = 0; r < s_len; r++) {
        if (mark[s[r]] != 0) {
            if (len < r - l) {
                len = r - l;
            }
            while (l < r) {
                mark[s[l]] = 0;
                if (s[l++] == s[r]) {
                    break;
                }
            }
        }
        mark[s[r]] = 1;
    }
    if (len < r - l) {
        len = r - l;
    }

    return len;
}