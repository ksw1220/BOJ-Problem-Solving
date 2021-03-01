#include<iostream>
#include<vector>
using namespace std;

typedef struct task {
	int location, priority;
};
vector<task> tasks;


int main() {
	int T, N, target, tmp;
	cin >> T;
	while (T--) {
		tasks.clear();
		cin >> N >> target;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			tasks.push_back({ i,tmp });
		}
		while (!tasks.empty()) {
			bool chk = true;
			task now = tasks[0];
			tasks.erase(tasks.begin());
			for (int i = 0; i < tasks.size(); i++) {
				if (now.priority < tasks[i].priority) {
					chk = false;
					break;
				}
			}
			if (!chk)tasks.push_back(now);
			else if (now.location == target) {
				cout << N - tasks.size() << endl;
				break;
			}
		}
	}
	return 0;
}