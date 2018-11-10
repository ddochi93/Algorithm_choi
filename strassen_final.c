#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX 64


int threshold = 2;

void std_algorithm(int n, int **a, int **b, int **c);
void strassen(int n, int **a, int **b, int **c);


int main(void) {
	int n;
	int i, j, k = 0;
	printf("몇 x 몇 행렬을 계산하시겠습니까? (2의 멱승만 입력)");
	while (1) {
		scanf("%d", &n);
		if (n <= MAX)
			break;
		else
			printf("%d보다 작은 수를 입력하세요 : ", MAX);
	}
	int **a = NULL;
	int **b = NULL;
	int **c = NULL;

	a = (int **)malloc(sizeof(int*) * n);
	b = (int **)malloc(sizeof(int*) * n);
	c = (int **)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) {
		a[i] = (int *)malloc(sizeof(int) *n);
		b[i] = (int *)malloc(sizeof(int) *n);
		c[i] = (int *)malloc(sizeof(int) *n);
	}


	printf("a배열 입력 : ");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("b배열 입력 : ");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	printf("strassen algorithm 이용 : \n");
	strassen(n, a, b, c);


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("std_algorithm 이용 : \n");
	std_algorithm(n, a, b, c);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);
	return 0;
}



void std_algorithm(int n, int **a, int **b, int **c) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = 0;
			for (k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void strassen(int n, int **a, int **b, int **c) {
	if (n <= threshold) {
		std_algorithm(n, a, b, c);
	}
	else {
		int i, j, k = 0;
		int **a11 = (int **)malloc(sizeof(int*) * n / 2);
		int **a12 = (int **)malloc(sizeof(int*) * n / 2);
		int **a21 = (int **)malloc(sizeof(int*) * n / 2);
		int **a22 = (int **)malloc(sizeof(int*) * n / 2);
		int **b11 = (int **)malloc(sizeof(int*) * n / 2);
		int **b12 = (int **)malloc(sizeof(int*) * n / 2);
		int **b21 = (int **)malloc(sizeof(int*) * n / 2);
		int **b22 = (int **)malloc(sizeof(int*) * n / 2);

		int **m1 = (int **)malloc(sizeof(int*) * n / 2);
		int **m2 = (int **)malloc(sizeof(int*) * n / 2);
		int **m3 = (int **)malloc(sizeof(int*) * n / 2);
		int **m4 = (int **)malloc(sizeof(int*) * n / 2);
		int **m5 = (int **)malloc(sizeof(int*) * n / 2);
		int **m6 = (int **)malloc(sizeof(int*) * n / 2);
		int **m7 = (int **)malloc(sizeof(int*) * n / 2);

		int **sum1 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum2 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum3 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum4 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum5 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum6 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum7 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum8 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum9 = (int **)malloc(sizeof(int*) * n / 2);
		int **sum10 = (int **)malloc(sizeof(int*) * n / 2);

		for (i = 0; i < n / 2; i++) {
			a11[i] = (int*)malloc(sizeof(int) * n / 2);
			a12[i] = (int*)malloc(sizeof(int) * n / 2);
			a21[i] = (int*)malloc(sizeof(int) * n / 2);
			a22[i] = (int*)malloc(sizeof(int) * n / 2);
			b11[i] = (int*)malloc(sizeof(int) * n / 2);
			b12[i] = (int*)malloc(sizeof(int) * n / 2);
			b21[i] = (int*)malloc(sizeof(int) * n / 2);
			b22[i] = (int*)malloc(sizeof(int) * n / 2);
			m1[i] = (int*)malloc(sizeof(int) * n / 2);
			m2[i] = (int*)malloc(sizeof(int) * n / 2);
			m3[i] = (int*)malloc(sizeof(int) * n / 2);
			m4[i] = (int*)malloc(sizeof(int) * n / 2);
			m5[i] = (int*)malloc(sizeof(int) * n / 2);
			m6[i] = (int*)malloc(sizeof(int) * n / 2);
			m7[i] = (int*)malloc(sizeof(int) * n / 2);

			sum1[i] = (int*)malloc(sizeof(int) * n / 2);
			sum2[i] = (int*)malloc(sizeof(int) * n / 2);
			sum3[i] = (int*)malloc(sizeof(int) * n / 2);
			sum4[i] = (int*)malloc(sizeof(int) * n / 2);
			sum5[i] = (int*)malloc(sizeof(int) * n / 2);
			sum6[i] = (int*)malloc(sizeof(int) * n / 2);
			sum7[i] = (int*)malloc(sizeof(int) * n / 2);
			sum8[i] = (int*)malloc(sizeof(int) * n / 2);
			sum9[i] = (int*)malloc(sizeof(int) * n / 2);
			sum10[i] = (int*)malloc(sizeof(int) * n / 2);
		}


		/*  A,B 4개로 분할 */
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				a11[i][j] = a[i][j];
				a12[i][j] = a[i][j + n / 2];
				a21[i][j] = a[i + n / 2][j];
				a22[i][j] = a[i + n / 2][j + n / 2];
				b11[i][j] = b[i][j];
				b12[i][j] = b[i][j + n / 2];
				b21[i][j] = b[i + n / 2][j];
				b22[i][j] = b[i + n / 2][j + n / 2];
			}
		}
		/*  M 행렬 계산에 필요한 A11 + A22 ... 계산 */
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				sum1[i][j] = a11[i][j] + a22[i][j];
				sum2[i][j] = b11[i][j] + b22[i][j];
				sum3[i][j] = a21[i][j] + a22[i][j];
				sum4[i][j] = b12[i][j] - b22[i][j];
				sum5[i][j] = b21[i][j] - b11[i][j];
				sum6[i][j] = a11[i][j] + a12[i][j];
				sum7[i][j] = a21[i][j] - a11[i][j];
				sum8[i][j] = b11[i][j] + b12[i][j];
				sum9[i][j] = a12[i][j] - a22[i][j];
				sum10[i][j] = b21[i][j] + b22[i][j];
			}
		}

		/* M1 ~ M7행렬 계산 */
		strassen(n / 2, sum1, sum2, m1);
		strassen(n / 2, sum3, b11, m2);
		strassen(n / 2, a11, sum4, m3);
		strassen(n / 2, a22, sum5, m4);
		strassen(n / 2, sum6, b22, m5);
		strassen(n / 2, sum7, sum8, m6);
		strassen(n / 2, sum9, sum10, m7);

		int **c11 = (int **)malloc(sizeof(int*) * n / 2);
		int **c12 = (int **)malloc(sizeof(int*) * n / 2);
		int **c21 = (int **)malloc(sizeof(int*) * n / 2);
		int **c22 = (int **)malloc(sizeof(int*) * n / 2);
		for (i = 0; i < n / 2; i++) {
			c11[i] = (int*)malloc(sizeof(int) * n / 2);
			c12[i] = (int*)malloc(sizeof(int) * n / 2);
			c21[i] = (int*)malloc(sizeof(int) * n / 2);
			c22[i] = (int*)malloc(sizeof(int) * n / 2);
		}

		/* 4등분된 행렬C에 m1~m7의계산값을 대입*/
		for (i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				c11[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
				c12[i][j] = m3[i][j] + m5[i][j];
				c21[i][j] = m2[i][j] + m4[i][j];
				c22[i][j] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];
			}
		}
		/* c의 부분배열을 다시 c에 합침 */
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				c[i][j] = c11[i][j];
				c[i][j + n / 2] = c12[i][j];
				c[i + n / 2][j] = c21[i][j];
				c[i + n / 2][j + n / 2] = c22[i][j];
			}
		}

		for (i = 0; i < n / 2; i++) {
			free(a11[i]);
			free(a12[i]);
			free(a21[i]);
			free(a22[i]);
			free(b11[i]);
			free(b12[i]);
			free(b21[i]);
			free(b22[i]);
			free(m1[i]);
			free(m2[i]);
			free(m3[i]);
			free(m4[i]);
			free(m5[i]);
			free(m6[i]);
			free(m7[i]);
			free(sum1[i]);
			free(sum2[i]);
			free(sum3[i]);
			free(sum4[i]);
			free(sum5[i]);
			free(sum6[i]);
			free(sum7[i]);
			free(sum8[i]);
			free(sum9[i]);
			free(sum10[i]);
		}
		free(a11);
		free(a12);
		free(a21);
		free(a22);
		free(b11);
		free(b12);
		free(b21);
		free(b22);
		free(m1);
		free(m2);
		free(m3);
		free(m4);
		free(m5);
		free(m6);
		free(m7);
		free(sum1);
		free(sum2);
		free(sum3);
		free(sum4);
		free(sum5);
		free(sum6);
		free(sum7);
		free(sum8);
		free(sum9);
		free(sum10);
	}
}