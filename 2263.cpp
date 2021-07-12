#include <stdio.h>

int inorder[100002], postorder[100002];
int indexInorder[100002];

void dfs(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd)
{
    int root = postorder[postorderEnd];
    if (inorderStart > inorderEnd || postorderStart > postorderEnd)
        return;

    printf("%d ", root);
    int rootIndex = indexInorder[root];
    int leftSize = rootIndex - inorderStart;

    dfs(inorderStart, rootIndex - 1, postorderStart, postorderStart + leftSize - 1);
    dfs(rootIndex + 1, inorderEnd, postorderStart + leftSize, postorderEnd - 1);
}
int main()
{
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &inorder[i]);
        indexInorder[inorder[i]] = i;
    }
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    dfs(0, N - 1, 0, N - 1);
    return 0;
}