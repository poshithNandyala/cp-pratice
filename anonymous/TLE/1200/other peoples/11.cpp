#include <cstdio>
char s[1000007];
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        long long ans = 0;
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; i * j <= n && s[i * j] != 49; ++j)
                ans += i * (s[i * j] == 48), s[i * j] = 50;
        printf("%lld\n", ans);
    }
    return 0;
}
