#include<iostream>
#include<vector>

// 重み付きグラフ
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) :to(to), w(w) {}
};
using Graph = std::vector<std::vector<Edge>>;

int main(void){
    int N,M;
    std::cin >> N >> M;
    Graph G(N);

    for(int i = 0; i < M; i++){
	int a,b;
	long long w;
        std::cin >> a >> b >> w;
	G[a].push_back(Edge(b,w));
    }
}
