#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable :4996)

#define INF 999999
using namespace std;

class Edge {
public:
	int node[2];
	int distance;
	Edge(int x, int y, int distance) {
		this->node[0] = x;
		this->node[1] = y;
		this->distance = distance;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;

	}
};


void dijkstra(int n, int **w, vector<Edge> &f) {           //&필요
	int vnear = 0;
	//vector<Edge> e;
	int *touch = (int*)malloc((n + 1) * sizeof(int));
	int *length = (int*)malloc((n + 1) * sizeof(int));
	f.clear();   // f= 0;
	for (int i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = w[1][i];
	}

	for (int repeat = 1; repeat <= n - 1; repeat++) {
		int min = INF;
		for (int i = 2; i <= n; i++) {
			if (length[i] >= 0 && length[i] <= min) {
				min = length[i];
				vnear = i;
			}
		}

		//e.push_back(Edge(touch[vnear], vnear, w[touch[vnear]][vnear]));
		f.push_back(Edge(touch[vnear], vnear, w[touch[vnear]][vnear]));

		for (int i = 2; i <= n; i++) {
			if (length[vnear] + w[vnear][i] < length[i]) {
				length[i] = length[vnear] + w[vnear][i];
				touch[i] = vnear;
			}
			//length[vnear] = -1;   //여기서 실수..
		}
		length[vnear] = -1;
	}
}

int main(void) {
	vector<Edge> f;
	int n = 0;  //vertex 갯수
	int **w = NULL;
	printf("Vertex의 갯수를 입력하시오 : ");
	scanf("%d", &n);
	w = (int **)malloc((n + 1) * sizeof(int *));
	for (int i = 0; i < n + 1; i++) {
		w[i] = (int*)malloc((n + 1) * sizeof(int));
	}

	printf("그래프를 인접행렬식으로 입력 : ");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}

	dijkstra(n, w, f);
	printf("집합 F : \n");
	for (int i = 0; i < (int)f.size(); i++)
		cout << "(" << f[i].node[0] << "," << f[i].node[1] << ") - 가중치 : " << f[i].distance << endl;

	for (int i = 0; i < n + 1; i++)
		free(w[i]);
	free(w);
	return 0;
}