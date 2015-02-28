#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

const static int N = 10;

int g[N][N];

struct queen_node {
	int key;
	int pi;
	int id;
};

queen_node q[N];
int q_size;

//void init(queen_node q[N]) {
//	for(int i=0;i<N;++i) {
//		q[i].valid = (random()%100 > 50)? true: false;
//		q[i].key = random()%100;
//	}
//	sort(q);
//}

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

queen_node extract_min() {
	queen_node result;
	sort(0, q_size-1);
	result = q[0];
	for(int i=0;i<q_size-1;i++) {
		q[i] = q[i+1];
	}
	q[q_size-1] = result;
	--q_size;
	return result;
}

//void sort(queen_node q[N]) {
//	int p = 0;
//	for(int i=0;i<N;++i) {
//		if(q[i].valid) {
//			queen_node t = q[i];
//			for(int j=i;j>p;--j) {
//				q[j] = q[j-1];
//			}
//			q[p++] = t;
//		}
//	}
//	q_size = p;
//	sort(0,p-1);
//}

void display(const queen_node (q)[N]) {
	for(int i=0;i<N;++i) {
		cout << q[i].key << "\t";
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
		q[i].key = N*100;
		q[i].id = i;
	}
	q_size = N;
	q[random()%N].key = 0;

	while(q_size) {
		queen_node u = extract_min();
		for(int i=0;i<N;i++) {
			if(g[u.id][i]) {
				bool in_q = false;
				int v_location = 0;
				for(int j=0;j<q_size;j++) {
					if(q[j].id == i) {
						in_q = true;
						v_location = j;
					}
				}
				if(in_q && g[u.id][i] < q[v_location].key) {
					q[v_location].key = g[u.id][i];
					q[v_location].pi = u.id;
				}
			}
		}
		if(q_size == 9) {
			cout << "Root:" << u.id << "\t";
		} else {
			cout << u.pi << "-" << u.id << "\t";
		}
	}
	cout << endl;
}

int main() {
	random(g);
	cout << "******************Init****************" << endl;
	display(g);
	cout << "******************MST****************" << endl;
	mst_prim();
//	display(t);
	return 0;
}
