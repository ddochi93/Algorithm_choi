#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)
#define INF 999999

void printArray(int n, int **arr) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void path(int **p, int q, int r) {
	if (p[q][r] != 0) {
		path(p, q, p[q][r]);
		printf("v%d -> ", p[q][r]);
		path(p, p[q][r], r);
	}
}

void floyd(int n, int ** w, int **d, int **p) {
	int i, j, k;

	for (int i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			p[i][j] = 0;
	/* D = W */
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			d[i][j] = w[i][j];
		}
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					p[i][j] = k;
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}

int main(void) {
	int n; //정점의 개수
	printf("정점의 개수를 입력하시오 : ");
	scanf("%d", &n);

	int **w, ** d, **p = NULL;

	w = (int **)malloc((n + 1) * sizeof(int *)); // psedo-code와 c언어의 배열첨자 표현 차이 고려하여 n+1 만큼 할당.
	d = (int **)malloc((n + 1) * sizeof(int *));
	p = (int **)malloc((n + 1) * sizeof(int *));
	for (int i = 0; i < n + 1; i++) {
		w[i] = (int*)malloc((n + 1) * sizeof(int));
		d[i] = (int*)malloc((n + 1) * sizeof(int));
		p[i] = (int*)malloc((n + 1) * sizeof(int));
		for (int j = 0; j < n + 1; j++) {
			w[i][j] = 0;
			d[i][j] = 0;
			p[i][j] = 0;
		}
	}
	printf("그래프를 인접행렬식으로 입력하시오 : ");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	floyd(n, w, d, p);

	printf("최종 D 배열 : \n");
	printArray(n, d);
	printf("최종 P 배열 : \n");
	printArray(n, p);
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {*/
	int i = 0;
	int j = 0;
	printf("경로 출력할 출발지와 목적지 입력( ex) V2 부터 V5 까지 : 2 5 ) : ");
	scanf("%d %d", &i, &j);
	printf("V%d 부터 V%d 까지의 최단path( ()안의 수는 path의 length) : ", i, j);
	printf("V%d -> ", i);
	path(p, i, j);
	printf("V%d . (%d)\n", j, d[i][j]);
	/*	}
	}*/

	for (int i = 0; i < n + 1; i++) {
		free(w[i]);
		free(d[i]);
		free(p[i]);
	}
	free(w);
	free(d);
	free(p);
	return 0;
}