// File Name: C.cpp
// Author: YangYue
// Created Time: Fri Jun 13 00:04:42 2014
//headers 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<LL, LL>PLL;
typedef pair<LL,int>PLI;

#define lch(n) ((n<<1))
#define rch(n) ((n<<1)+1)
#define lowbit(i) (i&-i)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define MP make_pair
#define PB push_back

class TreeColoring {
public:
int N, Q;
int curValue = startSeed;
int startSeed, threshold, maxDist;
int genNextRandom() {
    curValue = (curValue * 1999 + 17) % 1000003;
    return curValue;
}
int how[MaxN];
int parent[MaxN];
int queryType[MaxN];
int queryNode[MaxN];
void generateInput() {
    for (int i = 0; i < N-1; i++) {
        distance[i] = genNextRandom() % maxDist;
	parent[i] = genNextRandom();
        if (parent[i] < threshold) {
            parent[i] = i;
        } else {
            parent[i] = parent[i] % (i + 1);
        }
    }

    for (int i = 0; i < Q; i++) {
        queryType[i] = genNextRandom() % 2 + 1;
        queryNode[i] = genNextRandom() % N;
    }
}
int que[MaxN];
	void bfs(int s) {
		int front, tail;
		que[front = tail = 0] = s;
		for (; front <= tail; ++front) {
			int u = que[front];
			for (vector<int> :: iterator *it = edges[u].begin(); it != edges[u].end(); ++it) {
				int v = *it;
			}
		}
	}
	long long color(int N_, int Q_, int startSeed_, int threshold_, int maxDist_) {
		N = N_;
		Q = Q_;
		startSeed = startSeed_;
		threshold = threshold_;
		maxDist = maxDist_;
		LL sum = 0;
		for (int i = 0; i < N - 1; ++i) edges[parent[i]].push_back(i+1);
		bfs(0);
		for (int i = 0; i < Q; ++i) {

		}
	}
};


// hehe ~


