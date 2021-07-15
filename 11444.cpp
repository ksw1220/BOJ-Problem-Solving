#include <stdio.h>
#include <vector>

#define MOD 1000000007
using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix multipleMatrix(Matrix A, Matrix B)
{
    Matrix result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

int main()
{
    long long N;
    Matrix mat(2, vector<long long>(2, 0));
    Matrix acc(2, vector<long long>(2, 0));
    scanf("%lld", &N);
    mat[0][1] = mat[1][0] = mat[1][1] = 1;
    acc[0][0] = acc[1][1] = 1;

    while (N)
    {
        if (N % 2)
            acc = multipleMatrix(acc, mat);
        mat = multipleMatrix(mat, mat);
        N /= 2;
    }

    printf("%lld\n", acc[0][1]);
    return 0;
}