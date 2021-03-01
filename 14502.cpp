#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct pos { int x, y; };
vector<pos> v, emp;
queue<pos> que;
int N, M;
int map[9][9];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[9][9];
int main() {	
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) {
		scanf("%d", &map[i][j]);
		if (map[i][j] == 2)v.push_back({ i,j });
		if (map[i][j] == 0)emp.push_back({ i,j });
	}
	for (int i = 0; i < emp.size(); i++) {
		for (int j = i + 1; j < emp.size(); j++) {
			for (int k = j + 1; k < emp.size(); k++) {
				int tmp = 0;
				for (int it = 0; it < N; it++)for (int it_ = 0; it_ < M; it_++)visit[it][it_] = false;
				map[emp[i].x][emp[i].y] = map[emp[j].x][emp[j].y] = map[emp[k].x][emp[k].y] = 1;
				for (int iter = 0; iter < v.size(); iter++)que.push(v[iter]);
				while (!que.empty()) {
					pos now = que.front();
					que.pop();
					for (int d = 0; d < 4; d++) {
						int tox = now.x + dx[d];
						int toy = now.y + dy[d];
						if (tox < 0 || toy < 0 || tox >= N || toy >= M || map[tox][toy] != 0 || visit[tox][toy])continue;
						que.push({ tox,toy });
						visit[tox][toy] = true;
					}
				}
				for (int it = 0; it < N; it++)for (int it_ = 0; it_ < M; it_++)
					if (map[it][it_] == 0 && !visit[it][it_])tmp++;
				ans = max(ans, tmp);
				map[emp[i].x][emp[i].y] = map[emp[j].x][emp[j].y] = map[emp[k].x][emp[k].y] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}

