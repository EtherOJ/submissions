#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 7;
inline int read(register int x = 0, register char ch = getchar(), register int f = 0) {
    for (; !isdigit(ch); ch = getchar()) f = ch == '-';
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? -x : x;
}
struct node {
    int x, y, t;
} a[maxn];
int k[maxn], opt[maxn], tmp[maxn], vis[maxn], f[maxn];
int c1[maxn], c2[maxn], m;
int T, n;
inline void add(register int x, register int y, register bool op) {
    if (op)
        for (; x <= m + 1; x += x & (-x)) c2[x] += y;
    else
        for (; x <= m + 1; x += x & (-x)) c1[x] += y;
}
inline int ask(register int x, register bool op) {
    int ans = 0;
    if (op)
        for (; x > 0; x -= x & (-x)) ans += c2[x];
    else
        for (; x > 0; x -= x & (-x)) ans += c1[x];
    return ans;
}
int main() {
    //	freopen("1.out","w",stdout);
    T = read();
    register int cnt1 = 0, cnt2 = 0, cnt = 0;
    for (register int i = 1; i <= T; i++) {
        opt[i] = read();
        if (opt[i] == 1) {
            n++;
            a[n].t = read(), a[n].x = read(), a[n].y = read();
            vis[i] = n;
            tmp[n] = a[n].x;
        } else {
            k[i] = read();
        }
    }
    sort(tmp + 1, tmp + 1 + n);
    m = unique(tmp + 1, tmp + 1 + n) - 1 - tmp;
    for (register int i = 1; i <= n; i++) {
        register int cur = a[i].x;
        a[i].x = lower_bound(tmp + 1, tmp + 1 + m, a[i].x) - tmp;
        f[a[i].x] = cur;
    }
    //
    for (register int i = 1; i <= T; i++) {
        if (opt[i] == 1) {
            register int u = vis[i];
            if (a[u].t == 0)
                add(a[u].x, a[u].y, 0), cnt1++;
            else
                add(a[u].x, a[u].y, 1), cnt2++;
            if (cnt1 == 0 || cnt2 == 0) {
                printf("Peace\n");
                continue;
            }
        } else {
            register int u = vis[k[i]];
            if (a[u].t == 0) {
                cnt1--;
                add(a[u].x, -a[u].y, 0);
            } else {
                cnt2--;
                add(a[u].x, -a[u].y, 1);
            }
            if (cnt1 == 0 || cnt2 == 0) {
                printf("Peace\n");
                continue;
            }
        }
        register int l = 1, r = m, ans = 0, ans1 = 0, cur1 = 0, cur = 0;
        while (l <= r) {
            register int mid = l + r >> 1;
            register int sum1 = ask(mid, 0);
            register int sum2 = ask(m + 1, 1) - ask(mid - 1, 1);
            if (sum1 <= sum2)
                l = mid + 1, ans = mid, cur = sum1 > sum2 ? sum2 : sum1;
            else
                r = mid - 1;
        }
        l = ans + 1, r = m;
        cur1 = min(ask(l, 0), ask(m + 1, 1) - ask(l - 1, 1));
        ;
        if (cur1 == 0 && cur == 0) {
            printf("Peace\n");
            continue;
        }
        while (l <= r) {
            register int mid = l + r >> 1;
            register int sum1 = ask(mid, 0);
            register int sum2 = ask(m + 1, 1) - ask(mid - 1, 1);
            register int mn = sum1 > sum2 ? sum2 : sum1;
            if (mn == cur1)
                l = mid + 1, ans1 = mid;
            else
                r = mid - 1;
        }
        if (cur > cur1) {
            ans1 = ans;
            cur1 = cur;
        }
        printf("%d %d\n", f[ans1], cur1 << 1);
    }
    return 0;
}
/*
12
1 0 518 9367
1 1 356 8783
1 1 377 9646
1 1 950 2051
1 1 292 5039
2 5
1 0 548 7370
1 0 559 6176
1 1 589 7232
1 0 821 739
1 1 57 1100
1 0 58 3612


*/