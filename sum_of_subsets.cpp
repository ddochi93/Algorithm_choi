#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int w[1001] = { 0 , };
//bool include[1001] = { false };
const char * include[1001];
int W = 0;    // 구하려는 총합.
void sum_of_subsets(int, int, int);
bool promising(int, int, int);

void sum_of_subsets(int i, int weight, int total) {
	if (promising(i,weight,total)) {
		if (weight == W) {
			for (int idx = 0; idx <= i; idx++)
				cout<<  include[idx];
			cout << endl;
		}
		else {
			//strcpy(include[i + 1], "yes");
			//include[i + 1] = true;
			include[i + 1] = "yes";
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			//strcpy(include[i + 1], "no");
			include[i + 1] = "no";
			sum_of_subsets(i + 1, weight, total - w[i + 1]);
		}
	}
}

bool promising(int i,int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}


int main(void) {
	int n = 0;
	int total = 0;  //total
	printf("원소의 갯수(n)과 만드려는 총합(W) 입력 : ");
	scanf("%d %d", &n, &W);

	printf("원소 각각 입력(%d개) : ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	sort(w, w + n);          //교재 알고리즘은 이거 굳이안해도? 21라인

	for (int i = 0; i < n; i++)
		total += w[i];

	sum_of_subsets(-1, 0, total);
	//const char * fuck = "fuck";
	//printf("%s\n", fuck);
	/*string str[5];
	str[3] = "fucksdalkj";
	for (int i = 0; i < 5; i++) {
		cout << 5;
	}*/

	return 0;
}