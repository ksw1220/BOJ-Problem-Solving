#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> que;
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
            que.push(x);
        }
        else if (cmd == "pop")
        {
            if (que.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << que.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (que.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == "front")
        {
            if (que.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << que.front() << endl;
            }
        }
        else if (cmd == "back")
        {
            if (que.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << que.back() << endl;
            }
        }
    }
    return 0;
}