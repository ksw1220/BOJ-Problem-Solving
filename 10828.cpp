#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st;
int main()
{
    int N, x;
    string cmd;
    cin >> N;

    while (N--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> x;
            st.push(x);
        }
        else if (cmd == "pop")
        {
            if (st.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << st.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (st.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == "top")
        {
            if (st.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << st.top() << endl;
            }
        }
    }
    return 0;
}