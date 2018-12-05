#include <iostream>
using namespace std;

int n = 0;
int vcolor[1001] = { 0, };
bool W[1001][1001] = { 0, };	
int m = 0;

bool promising(int i) {
	int j;
	bool flag = true;   //switch
	j = 1; 
	while (j < i && flag) {
		if (W[i][j] && vcolor[i] == vcolor[j])
			flag = false;
		j++;
	}
	return flag;
}
void m_coloring(int i) {
	int color;
	if (promising(i)) {
		if (i == n) {
			for (int idx = 1; idx <= n; idx++) {
				cout << vcolor[idx];
			}
			cout << endl;
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}

		}	
	}
}

int main(void) {

	printf("몇 개의 노드? ");
	scanf("%d", &n);
	printf("그래프를 인접행렬로 입력 : ");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	printf("색깔 몇개?");
	scanf("%d", &m);

	m_coloring(0);
	
	return 0;
}