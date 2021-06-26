#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

vector<int> v, answer;
stack<int> st;
int main()
{
    int N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
        answer.push_back(-1);
    }
    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && v[st.top()] < v[i])
        {
            answer[st.top()] = v[i];
            st.pop();
        }

        st.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}