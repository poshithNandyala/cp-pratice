#include <cstdio>
using namespace std;

const int nn = 200005;

int n;
char a[nn];

int b[nn];

void work();

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        work();

    return 0;
}
void work()
{
    scanf("%d", &n);
    scanf("%s", a + 1);

    if (n & 1)
    {
        puts("-1");
        return;
    }

    bool bo1 = 0, bo2 = 0;
    int now = 0;
    for (int i = 1, lasn = 0; i <= n; i++)
    {
        if (a[i] == '(')
            now++;
        else
            now--;

        if (now > 0 || lasn > 0)
            b[i] = 1, bo1 = 1;
        else
            b[i] = 2, bo2 = 1;

        lasn = now;
    }
    if (now != 0)
    {
        puts("-1");
        return;
    }

    if (!bo1)
    {
        puts("1");
        for (int i = 1; i <= n; i++)
            printf("1 ");
        puts("");
        return;
    }

    printf("%d\n", bo1 + bo2);
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    puts("");

    return;
}