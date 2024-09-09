#include <stdio.h>
#include <string.h>

// 判断字符串是否是回文串
int isPalindrome(char* str)
{
    int len = strlen(str);
    for(int i = 0; i < len/2; i++)
    {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

// 构造回文串
void constructPalindrome(char* s, int k) {
    int len = strlen(s);
    char t[k + 1];
    t[k] = '\0';

    // 构造 t 为 s 的逆序
    for (int i = 0; i < k; i++) {
        t[i] = s[len - i - 1];
    }

    // 检查 s + t 和 t + s 是否为回文串
    char st[len + k + 1];
    char ts[len + k + 1];
    strcpy(st, s);
    strcat(st, t);
    strcpy(ts, t);
    strcat(ts, s);

    if (isPalindrome(st) || isPalindrome(ts)) {
        printf("%s\n", t);
    } else {
        printf("-1\n");
    }
}

int main() {
    char s[100001];
    int k;
    scanf("%s", s);
    scanf("%d", &k);

    constructPalindrome(s, k);

    return 0;
}