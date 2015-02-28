#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

const static int N = 100;

int g[N][N];
//int t[N][N];

struct queen_node {
	int key;
	queen_node *p;
	bool valid;
};

queen_node q[N];

void random(queen_node q[N]) {
	for(int i=0;i<N;++i) {
		q[i].valid = (random()%100 > 50)? true: false;
		q[i].key = random()%100;
	}
}

void random(int d[N][N]) {
	for(int i=0;i<N;++i) {
		for(int j=i;j<N;++j) {
			int temp = (random()%100 > 50)? random()%100 : 0;
			d[i][j] = temp;
			d[j][i] = temp;
		}
	}
}

void sort(int b, int e) {
	if(b < e) {
		int p = b;
		queen_node t;
		//Randomize
		int location = random()%(e-b) + b;
		t = q[location];
		for(int i=location;i<e;++i) {
			q[i] = q[i+1];
		}
		q[e] = t;
		//Sort
		for(int i=b;i<e;++i) {
			if(q[i].key <= q[e].key) {
				if(i != p) {
					t = q[i];
					for(int j=i;j>p;--j) {
						q[j] = q[j-1];
					}
					q[p] = t;
				} 
				p++;
			}
		}
		t = q[e];
		for(int j=e;j>p;--j) {
			q[j] = q[j-1];
		}
		q[p] = t;
		sort(b, p-1);
		sort(p+1, e);
	}
}

void sort(queen_node q[N]) {
	int p = 0;
	for(int i=0;i<N;++i) {
		if(q[i].valid) {
			queen_node t = q[i];
			for(int j=i;j>p;--j) {
				q[j] = q[j-1];
			}
			q[p++] = t;
		}
	}
	sort(0,p-1);
}

void display(const queen_node (q)[N]) {
	for(int i=0;i<N;++i) {
		cout << q[i].key << "-" << q[i].valid << "\t";
	}
	cout << endl;
}

void display(int  (d)[N][N]) {
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			cout << d[i][j] << "\t";
		}
		cout << "\n\n"  << endl;
	}
}

void mst_prim() {
	for(int i=0;i<N;++i) {
		q[i].key = 1000;
		q[i].p = NULL;
	}

}

int main() {
//	random(g);
//	cout << "******************Init****************" << endl;
//	display(g);
//	cout << "******************MST****************" << endl;

	random(q);
	sort(q);
	display(q);
//	display(t);
	return 0;
}
