#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n, m, mod, tr[N][10], fail[N];
char s[N];

struct Matrix
{
    int a[N][N];
    Matrix() { memset(a, 0, sizeof(a)); }
    int* operator[](int x) { return a[x]; }
    Matrix operator*(Matrix & b)
    {
        Matrix out;
        int i, j, k;
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                for (k = 0; k < m; ++k)
                {
                    out[i][j] = (out[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return out;
    }
};

Matrix qpow(Matrix x, int y);

int main()
{
    int i, j, ans = 0;
    Matrix mul;

    scanf("%d%d%d%s", &n, &m, &mod, s + 2);
    
    for (i = 0; i <= 9; ++i) tr[0][i] = 1;

    for (i = 1; i <= m; ++i)
    {
    	tr[i][s[i + 1] - '0'] = i + 1;
    	for (j = 0; j <= 9; ++j)
    	{
    		if (s[i + 1] - '0' == j) fail[i + 1] = tr[fail[i]][j];
    		else tr[i][j] = tr[fail[i]][j];
    		++mul[i - 1][tr[i][j] - 1];
		}
	}

    mul = qpow(mul, n);

    for (i = 0; i < m; ++i) ans = (ans + mul[0][i]) % mod;

    cout << ans;

    return 0;
}

Matrix qpow(Matrix x, int y)
{
    Matrix out;
    for (int i = 0; i < m; ++i) out[i][i] = 1;
    while (y)
    {
        if (y & 1) out = out * x;
        x = x * x;
        y >>= 1;
    }
    return out;
}
