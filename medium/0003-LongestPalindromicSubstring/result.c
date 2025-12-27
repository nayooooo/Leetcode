static void deleteDp(char ***dp, int s_len)
{
    if (*dp) {
        for (int i = 0; i < s_len; i++) {
            if ((*dp)[i]) {
                free((void *)(*dp)[i]);
                (*dp)[i] = NULL;
            }
        }
        free((void *)*dp);
        *dp = NULL;
    }
}

char* longestPalindrome(char* s) {
    int s_len = strlen(s);
    int len_max = 1;
    int target = 0;
    char **dp = (char **)malloc(s_len * sizeof(char *));
    if (dp == NULL) {
        return NULL;
    }
    for (int i = 0; i < s_len; i++) {
        dp[i] = (char *)malloc((s_len - i) * sizeof(char));
        if (dp[i] == NULL) {
            deleteDp(&dp, s_len);
            return NULL;
        }
        memset((void *)dp[i], 0, (s_len - i) * sizeof(char));
    }

    for (int i = 0; i < s_len; i++) {
        dp[i][i - i] = 1;
        if (i + 1 < s_len) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1 - i] = 1;
                if (len_max < 2) {
                    len_max = 2;
                    target = i;
                }
            }
        }
    }

    for (int len = 3; len <= s_len; len++) {
        for (int i = 0; i <= s_len - len; i++) {
            int j = i + len - 1;
            if (dp[i + 1][j - 1 - (i + 1)]) {
                if (s[i] == s[j]) {
                    dp[i][j - i] = 1;
                    if (len_max < len) {
                        len_max = len;
                        target = i;
                    }
                }
            }
        }
    }

    deleteDp(&dp, s_len);

    char *result = (char *)malloc((len_max + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    strncpy(result, &s[target], len_max);
    result[len_max] = '\0';
    return result;
}