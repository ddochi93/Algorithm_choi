
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)


int minmult(int n, const int * d, int **p) {
	int i, j, k, diagonal;
	int min = 99999;
	int **m = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i < n + 1; i++) {
		m[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < n + 1; j++) {
			m[i][j] = 0;
			p[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++)
		m[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			min = 99999; // �̰� ��
			j = i + diagonal;
			for (k = i; k <= j - 1; k++) {            //÷�� ǥ���� ?
				if (min > m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]) {
					min = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
					m[i][j] = min;
					p[i][j] = k;
				}

			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}

	return m[1][n];
}

void order(int **p, int i, int j) {
	int k = 0;
	if (i == j)
		printf("A%d", i);
	else {
		k = p[i][j];
		printf("(");
		order(p, i, k);
		order(p, k + 1, j);
		printf(")");
	}
}



int main(void) {
	int n;
	printf("����� ���� �Է� : ");
	scanf("%d", &n);

	int * d = (int *)malloc(sizeof(int) * (n + 1));    // ����� ������ ������ �迭(d0�� ù��° ����� ���)   
	printf("d%d���� d%d���� �Է� : ", 0, n);

	for (int i = 0; i <= n; i++) {
		scanf("%d", &d[i]);
	}

	int ** p = (int **)malloc(sizeof(int*) * (n + 1));  // ������ ������ �������� ������ ��Ÿ���� ���� �迭
	for (int i = 0; i < n + 1; i++) {
		p[i] = (int *)malloc(sizeof(int) * (n + 1));
	}
	//int res = 0;
	int res = minmult(n, d, p);
	order(p, 1, n);
	printf("��� : %d", res);

	return 0;
}