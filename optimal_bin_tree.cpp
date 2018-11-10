#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable :4996)

struct nodetype {
	int key;
	struct nodetype * left;
	struct nodetype * right;
};

typedef struct nodetype * node_pointer;
//void search(node_pointer, int, node_pointer &p);
void optsearchtree(int n, float * p, float & minavg, int **R);

void optsearchtree(int n, float * p, float & minavg, int **R) {
    float min = 9999;
	float sum = 0;
	int i, j, k, diagonal;
	float **A = (float**)malloc(sizeof(float *) * (n + 2));
	for (i = 0; i < n + 2; i++) {
		A[i] = (float *)malloc(sizeof(float) * (n + 1));
	}

	for (i = 0; i < n + 2; i++) {
		for (j = 0; j < n + 1; j++) {
			A[i][j] = 0;
			R[i][j] = 0;
		}
	}
	
	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			min = 9999; 
			sum = 0;
			j = i + diagonal;
			for (k = i; k <= j; k++) {
				if (min > A[i][k - 1] + A[k + 1][j]) {
					min = A[i][k - 1] + A[k + 1][j];
					A[i][j] = min;
					R[i][j] = k;
					//printf("%f\n", min);
				}
			/*	A[i][j] += p[k];*/
				sum += p[k];
			}
			A[i][j] = min + sum;
		}
	}
	printf("A 배열 : \n");
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%.3f ", A[i][j]);
		}
		printf("\n");
	}
	printf("R 배열 : \n");
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	minavg = A[1][n];
}



int main(void) {
	int n;
	float minavg = 0;
	printf("key가 몇 개 있는가? ");
	scanf("%d", &n);
	node_pointer s = (node_pointer )malloc(sizeof(nodetype) * (n + 1));
	printf("p[%d] 부터 p[%d]까지 입력 하시오(소수 형태로 입력하시오) : ", 1, n);
	float *p = (float *)malloc(sizeof(float) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%f", &p[i]);
	}
	int **R = (int**)malloc(sizeof(int *) * (n + 2));
	for (int i = 0; i < n + 2; i++) {
		R[i] = (int *)malloc(sizeof(int) * (n + 1));
	}

	optsearchtree(n, p, minavg, R);
	printf("minavg : %f\n", minavg);

	return 0;
}