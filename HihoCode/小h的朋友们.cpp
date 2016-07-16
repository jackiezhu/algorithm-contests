#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

typedef struct Matrix
{
    long long ma[15][15];
}Matrix;

Matrix A;   // 矩阵A
Matrix B;   // 保存最后的结果
Matrix unit;// 单位矩阵，用于在下面的fun函数中

const int MOD = (1e9 + 7);
int n = 2;
// 两个矩阵相乘
Matrix Mul(Matrix m1, Matrix m2)
{
    Matrix c;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            c.ma[i][j] = 0;
            for(int k=0; k<n; ++k)
            {
                c.ma[i][j] += m1.ma[i][k] % MOD * m2.ma[k][j] % MOD;
                c.ma[i][j] %= MOD;
            }
        }
    return c;
}

// 二分法求矩阵的幂
void fun(long long num)
{
    Matrix in = A;
    Matrix un = unit;
    
    while(num > 1)
    {
        if(num & 1)  
        {
            --num;
            un = Mul(in, un);   
        }
        else
        {
            num >>= 1;
            in = Mul(in, in);
            
        }
    }
    B = Mul(in, un);
}

long long pm (long long x, long long y) {
    x = (x % MOD + MOD) % MOD;
    long long r = 1;
    while (y) {
        if (y & 1) (r *= x) %= MOD;
        (x *= x) %= MOD;
        y >>= 1;
    }
    return r;
}

int main() {
    unit.ma[0][0] = 1;
    unit.ma[1][1] = 1;
    int k1, k2;
    while (cin >> k1 >> k2) {
        
        long long x, y, Ax, Ay;
        cin >> x >> y >> Ax >> Ay;
        long long z;
        cin >> z;
        if (k1 == 0 && k2 == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (k2 == 0) {
            if (x <= z) cout << Ax * pm (k1, z - x) % MOD << endl;
            else cout << Ax * pm (pm (k1, MOD - 2), x - z) % MOD << endl;
            return 0;
        }
        if (k1 == 0) {
            if ((x & 1) == (z & 1)) {
                if (x <= z) cout << Ax * pm (k2, (z - x) / 2) % MOD << endl;
                else cout << Ax * pm (pm (k2, MOD - 2), (x - z) / 2) % MOD << endl;
            } else {
                if (y <= z) cout << Ay * pm (k2, (z - y) / 2) % MOD << endl;
                else cout << Ay * pm (pm (k2, MOD - 2), (y - z) / 2) % MOD << endl;
            }
            return 0;
        }
        A.ma[0][0] = k1;
        A.ma[0][1] = k2;
        A.ma[1][0] = 1;
        A.ma[1][1] = 0;
        fun(x-2);
        long long X = B.ma[0][0];
        long long Y = B.ma[0][1]; //Ax
        fun(y-2);
        long long XX = B.ma[0][0];
        long long YY = B.ma[0][1]; //Bx
        fun(z-2);
        long long e = B.ma[0][0];
        long long f = B.ma[0][1];
        long long yyy = (Ax * XX%MOD - Ay * X %MOD+ MOD)%MOD * pm(Y * XX - X * YY, MOD-2)%MOD;
        long long xxx = (Ax * YY%MOD - Ay * Y%MOD + MOD)%MOD * pm(X * YY - Y * XX, MOD-2)%MOD;
        cout << (e * xxx%MOD + f * yyy%MOD) % MOD << endl;
    }
}


