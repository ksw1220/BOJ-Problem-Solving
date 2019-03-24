#include<stdio.h>
#include<queue>
using namespace std;
int map[1001][1001], dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
struct pos {
	int x, y;
};
queue<pos> cur, nex;
int main() {
	int N, M, cnt = 0, chk = 0;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) {
		scanf("%d", &map[i][j]);
		if (map[i][j] == 1) {
			cur.push({ i,j });
		}
	}
	while (1) {
		while (!nex.empty()) {
			map[nex.front().x][nex.front().y] = 1;
			cur.push(nex.front());
			nex.pop();
		}
		if (cur.empty())break;
		cnt++;
		while (!cur.empty()) {
			pos now = cur.front();
			cur.pop();
			for (int d = 0; d < 4; d++) {
				int tox = now.x + dx[d];
				int toy = now.y + dy[d];
				if (tox < 0 || toy < 0 || tox >= N || toy >= M ||	map[tox][toy] != 0)continue;
				nex.push({ tox,toy });
				map[tox][toy] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (!map[i][j])chk++;
	if (!chk)printf("%d", cnt - 1);
	else printf("-1");
	return 0;
}