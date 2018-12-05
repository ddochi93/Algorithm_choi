#include <iostream>

using namespace std;

int n = 0;
bool W[1001][1001] = { 0 , };
int vindex[1001] = { 1, };              //1000�� �ȳѾ�ٰ� ����.

bool promising(int i) {
	int j;
	bool flag; //switch 

	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		flag = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		flag = false;
	else {
		flag = true;
		j = 1;
		while (j < i && flag) {
			if (vindex[i] == vindex[j])
				flag = false;
			j++;
		}
	}
	return flag;
}

void hamiltonian(int i) {
	int j;
	if (promising(i)) {            //�������� �������� ������ ������� �ʴ´�.
		if (i == n - 1) {
			cout << "1 ";
			for (int idx = 1; idx <= n - 1; idx++)
				cout << vindex[idx] << " ";
			cout << "1 " << endl;
		}
		else {
			for (j = 2; j <= n; j++) {
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}
		}
	}
}

int main(void) {
	printf("vertex�� ���� �Է� : ");
	scanf("%d", &n);
	printf("�׷����� �������(W)�� �Է� : ");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> W[i][j];               // ���� 1 �񿬰� 0
	}

	cout << endl << endl;
	//cout << "1 ";
	hamiltonian(0);
	//cout << "1  " << endl;

	return 0;
}