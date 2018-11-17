#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 6;    // ��ü������ 5���� ���.

typedef int index;
typedef index set_pointer;

struct nodetype {
	index parent;
	int depth;
};

typedef nodetype universe[n+1];   //? �̰Եǳ�?
universe U;

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

void makeset(index i) {
	U[i].parent = i;
	U[i].depth = 0;
}

set_pointer find(index i) {
	index j;

	j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;                                               //���⼭ �ε��� ������ �߸��ȵ�.
}

void merge(set_pointer p, set_pointer q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth = U[q].depth + 1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth) {
		U[p].parent = q;
	}
	else {
		U[q].parent = p;
	}
}

bool equal(set_pointer p, set_pointer q) {
	if (p == q) {
		return true;
	}
	else {
		return false;
	}
}

void initial(int n) {
	index i;
	for (i = 1; i <= n; i++) {                           //������� ����.
		makeset(i);
	}
}

void kruskal(int n, int m, vector<Edge> E, vector<Edge> & F ) {
	index i = 0;
	//intdex j;
	set_pointer p, q;
	//Edge e = new
	for (int i = 0; i < (int)E.size(); i++) {
		printf("%d %d - %d\n", E[i].node[0], E[i].node[1],E[i].distance);
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < (int)E.size(); i++) {
		printf("%d %d - %d\n", E[i].node[0], E[i].node[1], E[i].distance);
	}
	//F = { 0 };
	initial(n);
	
	while ((int)F.size() < (n - 1)) {

		//printf(" edge: %d\n", E[i].node[0]);
		p = find(E[i].node[0]);
		q = find(E[i].node[1]);
		printf("%d���� p�� %d q�� %d\n", i, p, q);
		if (!equal(p, q)) {
			printf("%d�� %d�� ��ģ��? \n", E[i].node[0], E[i].node[1]);
			merge(p, q);
			F.push_back(E[i]);
		}
		i++;
	}

}

int main(void) {
	//int n = 6; // ����� ����
	int m = 10; // ������ ����
	vector<Edge> E;
	vector<Edge> F;

	//printf("%d\n\n", F.size());

	//E.push_back(Edge(1, 2, 1));
	//E.push_back(Edge(1, 3, 3));
	//E.push_back(Edge(2, 3 ,3));
	//E.push_back(Edge(2, 4, 6));
	//E.push_back(Edge(3, 4, 4));
	//E.push_back(Edge(3, 5, 2));
	//E.push_back(Edge(4, 5, 5));
	/*E.push_back(Edge(1, 5, 1));
	E.push_back(Edge(1, 2, 7));
	E.push_back(Edge(1, 4, 6));
	E.push_back(Edge(1, 3, 4));
	E.push_back(Edge(3, 2, 2));
	E.push_back(Edge(3, 4, 5));
	E.push_back(Edge(4, 2, 3));
	E.push_back(Edge(5, 4, 1));*/            //1�ߺ��Ǵ°� ��� ó��????????
	E.push_back(Edge(1, 2, 9));
	E.push_back(Edge(1, 3, 12));
	E.push_back(Edge(1, 4, 8));
	E.push_back(Edge(1, 6, 11));
	E.push_back(Edge(2, 3, 2));
	E.push_back(Edge(3, 4, 6));
	E.push_back(Edge(3, 5, 7));
	E.push_back(Edge(4, 5, 3));
	E.push_back(Edge(4, 6, 4));
	E.push_back(Edge(5, 6, 13));
	

	kruskal(n,m,E,F );
	printf("���� F : \n");
	for (int i = 0; i < (int)F.size(); i++) {
		printf("(%d %d) - ����ġ:%d\n", F[i].node[0],F[i].node[1], F[i].distance);
	}


	return 0;
}