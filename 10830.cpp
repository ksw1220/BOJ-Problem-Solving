#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> mulMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
    int size = A.size();
    vector<vector<int>> re(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                re[i][j] += A[i][k] * B[k][j];
                re[i][j] %= 1000;
            }
        }
    }
    return re;
}
int main()
{
    int N;
    long long B;
    vector<vector<int>> mat(N, vector<int>(N, 0));
    scanf("%d %lld", &N, &B);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &mat[i][j]);

    vector<vector<int>> answer(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        answer[i][i] = 1;

    while (B > 0)
    {
        if (B % 2)
            answer = mulMatrix(answer, mat);
        mat = mulMatrix(mat, mat);
        B /= 2;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}